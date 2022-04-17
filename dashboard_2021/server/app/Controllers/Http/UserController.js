'use strict'

const User = use('App/Models/User')

class UserController {
  async me({ auth, response }) {
    response.send({
      status: 'success',
      data: auth.user,
    })
  }

  async register({ request }) {
    const {username, email, password} = request.all();

    // console.log(username, email, password);
    await User.create({
        username,
        email,
        password
    });
    return this.login(...arguments);
  }

  async login({ auth, request, response }) {
    const { email, password } = request.only(['email', 'password'])
    try {
      const token = await auth.attempt(email, password);

      return response.send({
        status: 'success',
        data: token
      })
    } catch (error) {
      return response.status(400).send({
        status: 'error',
        code: error.code,
        message: error.message
      })
    }
  }

  async logout({response}) {
    try {
      return response.send({status: 'success'})
    } catch (err) {
      return response.status(400).send({
        status: 'error',
        code: error.code,
        message: error.message
      })
    }
  }
}

module.exports = UserController
