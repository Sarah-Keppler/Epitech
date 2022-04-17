<template>
  <div>
    <v-list-item two-line>
      <v-list-item-content>
        <v-list-item-title class="text-h5">
          {{ snippet.title }}
        </v-list-item-title>
        <v-list-item-subtitle> Launch: {{ date }}, By {{ snippet.channelTitle }}</v-list-item-subtitle>
      </v-list-item-content>
    </v-list-item>


    <v-list-item>
      <v-list-item-icon>
        <v-icon>mdi-eye-arrow-right-outline</v-icon>
      </v-list-item-icon>
      <v-list-item-subtitle>{{statistics.viewCount}} views</v-list-item-subtitle>
    </v-list-item>

    <v-list-item>
      <v-list-item-icon>
        <v-icon>mdi-thumb-up-outline</v-icon>
      </v-list-item-icon>
      <v-list-item-subtitle>{{statistics.likeCount}} likes</v-list-item-subtitle>
    </v-list-item>

    <v-list-item>
      <v-list-item-icon>
        <v-icon>mdi-thumb-down-outline</v-icon>
      </v-list-item-icon>
      <v-list-item-subtitle>{{statistics.dislikeCount}} dislikes</v-list-item-subtitle>
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
