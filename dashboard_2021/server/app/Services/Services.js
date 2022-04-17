const Weather = use('App/Services/Weather');
const Youtube = use('App/Services/Youtube');

class Services {
  constructor () {
    this.about = {
      "client": {
        "host": "192.168.86.234"
      },
      "server": {
        "current_time": "0",
        "services": [{
          "name": "Weather",
          "widgets": [{
            "name": "City temperature",
            "description": "display temperature for a city",
            "params": [{
              "name": "city",
              "type": "string"
            }]
          }]
        },{
          "name": "Youtube",
          "widgets": [{
            "name": "Subscription",
            "description": "display number of subscription of a channel",
            "params": [{
              "name": "link youtube channel",
              "type": "string"
            }]
          },{
            "name": "Views",
            "description": "display number of view from youtube video",
            "params": [{
              "name": "link youtube video",
              "type": "string"
            }]
          },{
            "name": "Comments",
            "description": "display n number of comments from youtube video",
            "params": [{
              "name": "link youtube video",
              "type": "string"
            },{
              "name": "number max",
              "type": "integer"
            }]
          }]
        }]
      }
    }
    this.refreshFunctions = [
      Weather.refreshCityTemperature,
      Youtube.displaySubs,
      Youtube.displayViews,
      Youtube.displayNComments
    ]
  }

  serviceManagement(instance) {
    let f = 0;
    const services = this.about.server.services

    for (let e = 0; e < services.length; e++) {
      for (let i = 0; i < services[e].widgets.length; i++, f++) {
        if (services[e].widgets[i].name == instance.widget) {
          return this.refreshFunctions[f](instance)
        }
      }
    }
  }

}

module.exports = new Services()