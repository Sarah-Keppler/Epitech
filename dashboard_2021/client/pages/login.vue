<template>
  <v-container>

    <v-row justify="center">
      <v-col cols="auto">
        <p class="font-weight-light headline mt-4">
          Login
        </p>
      </v-col>
    </v-row>

    <v-row justify="center">
      <v-col cols="12" md="6">
        <v-text-field label="Email" placeholder="Email" v-model="email">
        </v-text-field>
      </v-col>
    </v-row>

    <v-row justify="center">
      <v-col cols="12" md="6">
        <v-text-field
          :append-icon="show ? 'mdi-eye' : 'mdi-eye-off'"
          :type="show ? 'text' : 'password'"
          name="input-10-2"
          label="Password"
          @click:append="show = !show"
          v-model="password"
        ></v-text-field>
      </v-col>
    </v-row>

    <v-row justify="center">
      <v-col cols="auto">
        <v-btn color="blue" dark @click="login">
          login
        </v-btn>
      </v-col>
    </v-row>

  </v-container>
</template>

<script>

export default {
  auth: false,
  data () {
    return {
      show: false,
      email: "",
      password: ""
    }
  },
  methods: {
    async login() {
      try {
        await this.$auth.loginWith('local', {
          data: {
            email: this.email,
            password: this.password
          },
        })

        this.$store.commit('snackbar/set', {
          msg: 'Welcome back amigo',
          color: 'success'
        })

        this.$router.push('/services')
      } catch (e) {

        this.$store.commit('snackbar/set', {
          msg: 'Invalid Email or Password',
          color: 'error'
        })
      }
    }
  }
}
</script>

<style>

</style>