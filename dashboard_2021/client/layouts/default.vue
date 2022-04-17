<template>
  <v-app>
    <!-- <client-only> -->
      <v-app-bar color="blue" dark fixed app>
        <v-toolbar-title class="mr-4">DASHBOARD</v-toolbar-title>
        <v-toolbar-items v-if="loggedIn">
          <v-btn text large to="/services">
            <v-icon small>mdi-widgets-outline</v-icon>
            services
          </v-btn>
        </v-toolbar-items>
        <v-spacer />
        <v-toolbar-items>
          <v-btn v-if="!loggedIn" text to="/register">Register</v-btn>
          <v-btn v-if="!loggedIn" text to="/login">Login</v-btn>
          <v-btn v-if="loggedIn" text @click="logout">Logout</v-btn>
        </v-toolbar-items>

      </v-app-bar>

      <v-main>
        <v-container>
          <Nuxt />
        </v-container>
      </v-main>

      <div>
        <v-snackbar v-model="snackbar" :timeout="6000" :color="snackbarColor">
          {{ snackbarTxt }}
          <template v-slot:action="{ attrs }">
            <v-btn dark text v-bind="attrs" @click="snackbar = false">
              Close
            </v-btn>
          </template>
        </v-snackbar>
      </div>

      <v-footer app>
        <span>&copy; {{ new Date().getFullYear() }}</span>
      </v-footer>
    <!-- </client-only> -->
  </v-app>
</template>

<script>
import { mapState } from 'vuex'

export default {
  computed: {
    ...mapState('auth', ['loggedIn']),
  },
  data () {
    return {
      snackbar: false,
      snackbarTxt: '',
      snackbarColor: '',
    }
  },
  created() {
    this.$store.watch(state => state.snackbar.date, () => {
      this.snackbar = true
      this.snackbarTxt = this.$store.state.snackbar.msg
      this.snackbarColor = this.$store.state.snackbar.color
    })
  },
  methods: {
    async logout() {
      await this.$auth.logout()
      this.$router.push('/login')
    },
  }
}
</script>
