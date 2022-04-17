export default {
  state() {
    return {
      date: 0,
      msg: '',
      color: ''
    }
  },

  mutations: {
    set (state, snack) {
      state.date = Date.now()
      state.msg = snack.msg
      state.color = snack.color
    }
  }
}