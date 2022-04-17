const { google } = require('googleapis');
const Env = use('Env');
const AppException = use('App/Exceptions/AppException')

class Youtube {

  displaySubs(instance)
  {
    let url = instance.params[`link youtube channel`]
    // console.log("url:", url)
    let idx = url.lastIndexOf("/")
    let vid = url.slice(idx + 1)
    return google.youtube('v3').channels.list({
      key: Env.get('YOUTUBE_API_KEY'),
      part: [
        "snippet",
        "statistics"
      ],
      id: vid,
    }).then((response) => {
      // console.log(response)
      const { data } = response
      // console.log(data)
      // data.items.forEach((item) => {
      //   console.log(`Title: ${item.snippet.title}\nNumber os subs: ${item.statistics.subscriberCount}`)
      // })
      return data.items[0]
    }).catch((err) => {throw new AppException("error for api displaySubs");})
  }

  displayViews(instance)
  {
    let url = instance.params[`link youtube video`]
    let idx = url.lastIndexOf("=")
    let vid = url.slice(idx + 1)
    // console.log(url, idx, vid)
    return google.youtube('v3').videos.list({
      key: Env.get('YOUTUBE_API_KEY'),
      part: [
        "snippet",
        "statistics"
      ],
      id: vid,
    }).then((response) => {
      const { data } = response;
      // console.log(data)
      // data.items.forEach((item) => {
        // console.log(`Title: ${item.snippet.title}\nNumbers of views: ${item.statistics.viewCount}`);
      // })
      return data.items[0]
    }).catch((err) => {throw new AppException("error for api displayViews");});
  }

  displayNComments(instance)
  {
    let url = instance.params[`link youtube video`]
    let n = instance.params[`number max`]
    let idx = url.lastIndexOf("=")
    let vid = url.slice(idx + 1)
    google.youtube('v3').videos.list({
      key: Env.get('YOUTUBE_API_KEY'),
      part: "snippet",
      id: vid,
    }).then((response) => {
      const { data } = response;
      // console.log(`Title: ${data.items[0].snippet.title}`);
    }).catch((err) => {throw new AppException("error for api display Comments");});

    return google.youtube('v3').commentThreads.list({
      key: Env.get('YOUTUBE_API_KEY'),
      part: "snippet",
      videoId: vid,
      maxResults: parseInt(n),
    }).then((response) => {
      const { data } = response;
      // data.items.forEach((item) => {
      //     console.log(`From ${item.snippet.topLevelComment.snippet.authorDisplayName}:\n\t${item.snippet.topLevelComment.snippet.textOriginal}\n`);
      // })
      return data.items
    }).catch((err) => {throw new AppException("error for api display Comments");});
  }
}

module.exports = new Youtube()