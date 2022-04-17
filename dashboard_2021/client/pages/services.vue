<template>
  <div>
    <grid-layout :layout.sync="layout"
      :col-num="12"
      :row-height="30"
      :margin="[30, 30]"
      :is-draggable="draggable"
      :is-resizable="resizable"
      :responsive="responsive"
      :vertical-compact="true"
      :use-css-transforms="true"
    >
      <grid-item v-for="(item, i) in layout"
        :key="i"
        :static="false"
        :minH="item.mh"
        :minW="item.mw"
        :x="item.x"
        :y="item.y"
        :w="item.w"
        :h="item.h"
        :i="item.i"
      >
        <v-card height="100%" class="card-outter">
          <!-- <v-container fill-height fluid> -->

          <div v-if="item.instance.widget == 'City temperature'">
            <city-weather-widget :instance="item.instance" :data="item.data"/>
          </div>

          <div v-else-if="item.instance.widget == 'Subscription'">
            <subscription-widget :instance="item.instance" :data="item.data"/>
          </div>

          <div v-else-if="item.instance.widget == 'Views'">
            <views-widget :instance="item.instance" :data="item.data"/>
          </div>

          <div v-else-if="item.instance.widget == 'Comments'">
            <comments-widget :instance="item.instance" :data="item"/>
          </div>

          <div v-else>
            <v-card-title>Unknown Widgets</v-card-title>
          </div>

          <v-card-actions class="card-actions">
            <v-btn color="primary" @click="deleteWidget(item)" icon>
              <v-icon>mdi-trash-can-outline</v-icon>
            </v-btn>
            <v-btn color="primary" @click="openUpdateWidget(item)" icon>
              <v-icon>mdi-pencil-outline</v-icon>
            </v-btn>
            <v-btn color="primary" @click="refreshWidget(item)" icon>
              <v-icon>mdi-reload</v-icon>
            </v-btn>
          </v-card-actions>
          <!-- </v-container> -->
        </v-card>
      </grid-item>
    </grid-layout>


    <v-dialog v-model="dialogUpdateInstance" max-width="1000px">
      <v-card>
        <v-container>

          <v-row justify="end" class="mt-1" @click="dialogUpdateInstance = false">
            <v-btn text>
              <v-icon>mdi-close</v-icon>
            </v-btn>
          </v-row>

          <v-row justify="center">
            <v-col cols="auto">
              <p class="font-weight-light headline mt-4 mb-8">
                Update "{{ updateInstance.widget }}" widget
              </p>
            </v-col>
          </v-row>

        <v-form v-model="validUpdate" ref="form" lazy-validation>
          <template v-for="(param, i) in params">
            <v-text-field v-if="param.type == 'string'" :key="i" :rules="rule" :label="param.name" :placeholder="param.name" v-model="updateInstance.params[param.name]" outlined/>
            <v-text-field v-else-if="param.type == 'integer'" :key="i" :rules="rule" type="number" :label="param.name" :placeholder="param.name" v-model="updateInstance.params[param.name]" outlined/>
          </template>
          <v-text-field type="number" :rules="rule" label="refresh" placeholder="refresh" v-model="updateInstance.refresh" min="0.5" outlined/>

          <v-row justify="center">
            <v-col cols="auto">
              <v-btn
                class="mb-6 mt-3"
                color="primary"
                :disabled="!validUpdate"
                @click="updateWidget"
                outlined
              >
                Update
              </v-btn>

            </v-col>
          </v-row>
        </v-form>
        </v-container>
      </v-card>
    </v-dialog>

    <v-dialog v-model="dialogAddInstance" max-width="1000px">
      <v-stepper v-model="e1">
        <v-stepper-header>
          <v-stepper-step :complete="e1 > 1" step="1">Services</v-stepper-step>
          <v-divider/>
        <v-stepper-step :complete="e1 > 2" step="2">Widgets</v-stepper-step>
          <v-divider/>
          <v-stepper-step step="3">Paremeters</v-stepper-step>
        </v-stepper-header>

        <v-stepper-items>

          <v-stepper-content step="1">
            <v-card flat min-height="300px">
              <template v-for="(service, i) in allInstances">
                <v-card :key="i" class="mb-4" outlined hover @click="selectSevice(service)">
                  <p class="body-1 my-2 ml-6">
                    {{ service.name }}
                  </p>
                </v-card>
              </template>
            </v-card>

            <v-btn text color="primary" @click="dialogAddInstance = false">Quit</v-btn>
            <v-btn text disabled>Back</v-btn>

          </v-stepper-content>

          <v-stepper-content step="2">
            <v-card flat min-height="300px">
              <template v-for="(wid, i) in widgets">
                <v-card :key="i" class="mb-4" outlined hover @click="selectWidget(wid)">
                  <p class="body-1 my-2 ml-6">
                    {{ wid.name }} : {{ wid.description }}
                  </p>
                </v-card>
              </template>
            </v-card>

            <v-btn text color="primary" @click="dialogAddInstance = false">Quit</v-btn>
            <v-btn text @click="e1--">Back</v-btn>

          </v-stepper-content>

          <v-stepper-content step="3">
            <v-card flat min-height="300px">
              <template v-for="(param, i) in params">
                <v-text-field v-if="param.type == 'string'" :key="i" :label="param.name" :placeholder="param.name" v-model="param.value" outlined/>
                <v-text-field v-else-if="param.type == 'integer'" :key="i" type="number" :label="param.name" :placeholder="param.name" v-model="param.value" outlined/>
              </template>
              <v-text-field type="number" label="refresh" placeholder="refresh" v-model="addInstance.refresh" min="0.5" outlined/>
            </v-card>

            <v-row>
              <v-col cols="auto"><v-btn text color="primary" @click="dialogAddInstance = false">Quit</v-btn></v-col>
              <v-col cols="auto"><v-btn text @click="e1--">Back</v-btn></v-col>
              <v-spacer/>
              <v-col cols="auto"><v-btn color="primary" @click="finishInstance(params)">Finish</v-btn></v-col>
            </v-row>

          </v-stepper-content>
        </v-stepper-items>
      </v-stepper>
    </v-dialog>

    <v-btn dark fixed right bottom fab color="primary" class="mb-8 mr-4" @click="dialogAddInstance = true">
      <v-icon>mdi-plus</v-icon>
    </v-btn>

  </div>
</template>

<script>
import { GridLayout, GridItem } from "vue-grid-layout"
import { mapActions } from 'vuex'
import CityWeatherWidget from '../components/cityWeatherWidget.vue'

export default {
  components: {
    GridLayout,
    GridItem,
    CityWeatherWidget
  },
  data() {
    return {
      e1: 1,
      validUpdate:true,
      layout: [],
      draggable: true,
      resizable: true,
      responsive: true,
      index: 0,
      instances: {},
      allInstances: [],
      widgets: [],
      params: [],
      dash: {h:30, w:12},
      widget: {h:7, w:3, mh:4, mw:2},
      pos: {x:0, y:0},
      dialogAddInstance: false,
      dialogUpdateInstance: false,
      addInstance: { service: "", widget: "", refresh: 100, params: {}},
      updateInstance: { service: "", widget: "", refresh: 100, params: {}},
      rule: [(v) => v != null && v != "" || "Don't play with me bro"],
    }
  },
  async created() {
    this.instances = await this.getInstances()
    this.allInstances = await this.getAllInstances()

    for (let e = 0; e < this.instances.length; e++) {
      this.addWidget(this.instances[e])
      this.refreshWidget(this.layout[e])

      this.createAutoUpdate(this.layout[e])
      // this.layout[e].timer = window.setInterval(() => {this.refreshWidget(this.layout[e])}, this.layout[e].instance.refresh * 1000);

    }
    console.log(this.layout)
  },
  methods: {
    selectSevice(service) {
      this.addInstance.service = service.name
      this.widgets = service.widgets
      this.e1++
    },
    selectWidget(widget) {
      this.addInstance.widget = widget.name
      this.params = widget.params
      console.log(this.params)
      this.e1++
    },
    async finishInstance(params) {

      for (let e = 0; e < params.length; e++)
        this.addInstance.params[params[e].name] = params[e].value;

      await this.postInstance(this.addInstance)
        .then((instance) => {
          this.addWidget(instance)

          for (let e = 0; e < this.layout.length; e++)
            if (this.layout[e].instance.id == instance.id)
              this.refreshWidget(this.layout[e])

          this.$store.commit('snackbar/set', {msg: 'Widget added successfully', color: 'success'})
        })
        .catch(() => {
          this.$store.commit('snackbar/set', {msg: 'An error occured when adding the widget to dashboard', color: 'error'})
        })
      this.addInstance = {service: "", widget: "", refresh: 100, params: {}}
      this.dialogAddInstance = false
      this.e1 = 1
    },
    addWidget(instance) {
      this.layout.push({
        x:this.pos.x,
        y:this.pos.y,
        w: this.widget.w,
        h: this.widget.h,
        mw:this.widget.mw,
        mh:this.widget.mh,
        i:instance.id,
        instance:instance,
        data:{}})

      console.log(this.layout);
      if (this.pos.x == this.dash.w - this.widget.w) {
        this.pos.x = 0
        this.pos.y += this.widget.h
      } else
        this.pos.x += this.widget.w
    },
    async deleteWidget(item) {
      await this.deleteInstance(item.instance)
        .then((instance) => {
          for (let e = 0; e < this.layout.length; e++) {
            if (this.layout[e].instance.id == instance.id) {
              this.layout.splice(e, 1)
              break
            }
          }
          this.$store.commit('snackbar/set', {msg: 'Widget removed successfully', color: 'success'})
        })
        .catch(() => {
          this.$store.commit('snackbar/set', {msg: 'An error occured when removing the widget to dashboard', color: 'error'})
        })
    },
    openUpdateWidget(item) {
      this.dialogUpdateInstance = true

      //tkt i'm dump but that okay
      for (let e = 0; e < this.allInstances.length; e++)
        for (let i = 0; i < this.allInstances[e].widgets.length; i++)
          if (this.allInstances[e].widgets[i].name == item.instance.widget)
            this.params = this.allInstances[e].widgets[i].params

      this.updateInstance = item.instance
    },
    async updateWidget() {
      await this.patchInstance(this.updateInstance)
        .then((instance) => {
          for (let e = 0; e < this.layout.length; e++) {
            if (this.layout[e].instance.id == instance.id) {
              this.layout[e].instance == instance
              this.refreshWidget(this.layout[e])
              this.cancelAutoUpdate(this.layout[e])
              this.createAutoUpdate(this.layout[e])
              break
            }
          }
          this.$store.commit('snackbar/set', {msg: 'Widget updated successfully', color: 'success'})
          this.dialogUpdateInstance = false
        })
        .catch(() => {
          this.$store.commit('snackbar/set', {msg: 'An error occured when updating the widget to dashboard', color: 'error'})
        })
    },
    async refreshWidget(item) {
      // console.log("refresh: ", item.instance.widget);
      await this.refreshInstance(item.instance)
        .then((data) => {
          for (let e = 0; e < this.layout.length; e++) {
            if (this.layout[e].instance.id == item.instance.id) {
              this.layout[e].data = data
              break
            }
          }
        })
        .catch(() => {
          this.$store.commit('snackbar/set', {msg: 'An error occured when refreshing the widget from dashboard', color: 'error'})
        })
    },
    createAutoUpdate(item) {
      item.timer = window.setInterval(() => {this.refreshWidget(item)}, item.instance.refresh * 1000);
    },
    cancelAutoUpdate(item) {
      window.clearInterval(item.timer);
    },
    ...mapActions('instance', [
      'getAllInstances',
      'getInstances',
      'postInstance',
      'patchInstance',
      'deleteInstance',
      'refreshInstance'
    ]),
  },
  beforeDestroy() {
    for (let e = 0; e < this.layout.length; e++)
      this.cancelAutoUpdate(this.layout[e]);
  }
}
</script>

<style scoped>
.vue-grid-item .resizing {
  opacity: 0.9;
}
.vue-grid-item .static {
  background: #cce;
}
.vue-grid-item .text {
  font-size: 24px;
  text-align: center;
  position: absolute;
  top: 0;
  bottom: 0;
  left: 0;
  right: 0;
  margin: auto;
  height: 100%;
  width: 100%;
}
.vue-grid-item .no-drag {
  height: 100%;
  width: 100%;
}
.vue-grid-item .minMax {
  font-size: 12px;
}
.vue-grid-item .add {
  cursor: pointer;
}
.vue-draggable-handle {
  position: absolute;
  width: 20px;
  height: 20px;
  top: 0;
  left: 0;
  background-position: bottom right;
  padding: 0 8px 8px 0;
  background-repeat: no-repeat;
  background-origin: content-box;
  box-sizing: border-box;
  cursor: pointer;
}
.columns {
  -moz-columns: 120px;
  -webkit-columns: 120px;
  columns: 120px;
}

/* Set the button at the bottom of the cards */
.card-outter {
  padding-bottom: 50px;
}
.card-actions {
  position: absolute;
  bottom: 0;
}
</style>