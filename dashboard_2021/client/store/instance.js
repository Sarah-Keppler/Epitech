export const state = () => ({
  nameSpaced: true,
})

export const mutations = {}

export const actions = {
  getAllInstances({ _state }) {
    return this.$axios
      .get('/instance/all')
      .then((res) => {
        console.log('\nSucess to get all instances\n')
        return res.data
      })
      .catch((err) => {
        console.log('\nSucess to get all instances\n', err)
        return false
      })
  },
  getInstances({ _state }) {
    return this.$axios
      .get('/instance')
      .then((res) => {
        console.log('\nSucess to get your instances\n')
        return res.data
      })
      .catch((err) => {
        console.log('\nSucess to get your instances\n', err)
        return false
      })
  },
  postInstance({ _state }, instance) {
    return this.$axios
      .post('/instance', instance)
      .then((res) => {
        console.log('\nSucess to add instance\n')
        return res.data
      })
      .catch((error) => {
        console.log('\nError to add a instance\n', error.response)
        throw Error;
      })
  },
  refreshInstance({ _state }, instance) {
    return this.$axios
      .get(`/instance/refresh/${instance.id}`)
      .then((res) => {
        console.log(res)
        console.log('\nSucess to refresh instance\n')
        return res.data
      })
      .catch((error) => {
        console.log('\nError to refresh instance\n', error.response)
        throw Error;
      })
  },
  patchInstance({ _state }, instance) {
    return this.$axios
      .patch(`/instance/${instance.id}`, instance)
      .then((res) => {
        console.log('\nSucess to patch instance\n')
        return res.data
      })
      .catch((error) => {
        console.log('\nError to patch instance\n', error.response)
        throw Error;
      })
  },
  deleteInstance({ _state }, instance) {
    return this.$axios
      .delete(`/instance/${instance.id}`)
      .then((res) => {
        console.log('\nSucess to delete an instance\n')
        return res.data
      })
      .catch((error) => {
        console.log('\nError to delete an instance\n', error.response)
        throw Error;
      })
  },
}
