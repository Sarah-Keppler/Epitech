const axios = use('axios')
const Env = use('Env')

class Weather {
  async refreshCityTemperature(instance) {
    // console.log(instance)
    // console.log(`http://api.weatherapi.com/v1/current.json?key=${Env.get('WEATHER_API_KEY')}&q=${instance.params.city}&aqi=no`)
    const city = await axios.get(`http://api.weatherapi.com/v1/current.json?key=${Env.get('WEATHER_API_KEY')}&q=${instance.params.city}&aqi=no`)
    // console.log(city.data)
    return city.data
  }
}

module.exports = new Weather()