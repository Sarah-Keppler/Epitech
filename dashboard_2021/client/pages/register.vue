<template>
  <v-container>

    <v-row justify="center">
      <v-col cols="auto">
        <p class="font-weight-light headline mt-4">
          Register
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
          <v-text-field label="Username" placeholder="Username" v-model="username">
          </v-text-field>
      </v-col>
    </v-row>

    <v-row justify="center">
      <v-col cols="12" md="6">
        <v-text-field
          :append-icon="show ? 'mdi-eye' : 'mdi-eye-off'"
          :rules="[rules.required, rules.min]"
          :type="show ? 'text' : 'password'"
          name="input-10-2"
          label="Password"
          hint="At least 8 characters"
          value=""
          @click:append="show = !show"
          v-model="password"
        ></v-text-field>
      </v-col>
    </v-row>

    <v-row justify="center">
      <v-col cols="auto">
        <v-btn color="blue" dark @click="register">
          Register
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
      rules: {
        required: value => !!value || 'Required.',
        min: v => v.length >= 8 || 'Min 8 characters'
      },
        email: "",
        username: "",
        password: ""
    }
  },
  methods: {
    async register() {
      try {
        await this.$axios.post('auth/register', {
          username: this.username,
          email: this.email,
          password: this.password
        })

        await this.$auth.loginWith('local', {
          data: {
            email: this.email,
            password: this.password
          },
        })

        this.$store.commit('snackbar/set', {
          msg: 'Welcome amigo',
          color: 'success'
        })

        this.$router.push('/services')
      } catch (error) {

        this.$store.commit('snackbar/set', {
          msg: 'Email or Username already use',
          color: 'error'
        })
      }
    }
  }
}
</script>

<style>

</style>