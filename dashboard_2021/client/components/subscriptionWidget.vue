<template>
  <div>
    <v-list-item two-line>
      <v-list-item-content>
        <v-list-item-title class="text-h5">
          {{ snippet.title }}
        </v-list-item-title>
        <v-list-item-subtitle> Launch: {{ date }}, {{ snippet.country }}</v-list-item-subtitle>
      </v-list-item-content>
    </v-list-item>

    <v-card-text>
      <v-row align="center" justify="center" class="mt-12">
        <v-col
          class="text-h2"
          cols="auto"
        >
          {{ statistics.subscriberCount }} Sub
        </v-col>
      </v-row>
    </v-card-text>

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
      statistics: {},
      snippet: {},
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
    updateData(channel) {
      if (!channel.statistics)
        return
      this.statistics = channel.statistics
      this.snippet = channel.snippet
      this.date = this.dateFormat(channel.snippet.publishedAt)
    },
     dateFormat(date) {
      const options = {
          year: 'numeric', month: 'long', day: 'numeric',
          hour: 'numeric', minute: 'numeric',
          hour12: false,
      };
      var dateFormat = new Date(date);
      return new Intl.DateTimeFormat('en-US', options).format(dateFormat);
    }
  },
}
</script>
