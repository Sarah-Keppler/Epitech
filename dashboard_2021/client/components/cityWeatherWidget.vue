<template>
  <div>
    <v-list-item two-line>
      <v-list-item-content>
        <v-list-item-title class="text-h5">
          {{ location.name }}
        </v-list-item-title>
        <v-list-item-subtitle>{{ date }}, {{ current.condition.text }}</v-list-item-subtitle>
      </v-list-item-content>
    </v-list-item>

    <v-card-text>
      <v-row align="center">
        <v-col
          class="text-h2"
          cols="6"
        >
          {{ current.temp_c }}&deg;C
        </v-col>
        <v-col cols="6">
          <v-img
            :src="current.condition.icon"
            :alt="current.condition.text"
            width="92"
          ></v-img>
        </v-col>
      </v-row>
    </v-card-text>

    <v-list-item>
      <v-list-item-icon>
        <v-icon>mdi-send</v-icon>
      </v-list-item-icon>
      <v-list-item-subtitle>{{current.wind_mph}} mph</v-list-item-subtitle>
    </v-list-item>

    <v-list-item>
      <v-list-item-icon>
        <v-icon>mdi-cloud</v-icon>
      </v-list-item-icon>
      <v-list-item-subtitle>{{current.cloud}}%</v-list-item-subtitle>
    </v-list-item>
  </div>
</template>

<script>
export default {
  props: {
    instance: { type: Object, required: true },
    data: { type: Object, required: true },
  },
  data() {
    return {
      location: {},
      current: {condition:{}},
      date: ""
    }
  },
  watch: {
    data: {
      handler: 'updateData',
      deep: true,
    },
  },
  methods: {
    updateData({location, current}) {
      if (!location || !current)
        return
      this.location = location
      this.current = current
      this.date = this.dateFormat(this.current.last_updated_epoch)
    },
    dateFormat(date) {
      const options = {
          year: 'numeric', month: 'long', day: 'numeric',
          hour: 'numeric', minute: 'numeric',
          hour12: false,
      };
      var dateFormat = new Date(0);
      dateFormat.setUTCSeconds(date);
      return new Intl.DateTimeFormat('en-US', options).format(dateFormat);
    }
  },
}
</script>
