<template>
  <div>
    <v-list three-line>
      <template v-for="(item, index) in comments">
        <v-list-item
          :key="index"
        >
          <v-list-item-avatar>
            <v-img :src="item.snippet.topLevelComment.snippet.authorProfileImageUrl"></v-img>
          </v-list-item-avatar>

          <v-list-item-content>
            <v-list-item-title v-html="item.snippet.topLevelComment.snippet.authorDisplayName"></v-list-item-title>
            <v-list-item-subtitle v-html="item.snippet.topLevelComment.snippet.textOriginal"></v-list-item-subtitle>
          </v-list-item-content>
        </v-list-item>
      </template>
    </v-list>
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
      comments: [{snippet: {topLevelComment: { snippet: {}}}}]
    }
  },
  watch: {
    data: {
      handler: 'updateData',
      deep: true,
    },
  },
  methods: {
    updateData(comments) {
      if (!comments.data)
        return
      this.comments = comments.data
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
