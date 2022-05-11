package com.example.reddit_oauth.menu

import android.content.Intent
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import com.example.reddit_oauth.HomeActivity
import com.example.reddit_oauth.ProfileActivity
import com.example.reddit_oauth.R
import com.example.reddit_oauth.SettingsActivity

open class MainMenuActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_menu_activity)
        val toolbar: Toolbar = findViewById(R.id.toolbar)
        setSupportActionBar(toolbar)
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.main_menu,menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        super.onOptionsItemSelected(item)
        when (item?.itemId) {
            R.id.home -> {
                val actSwitcher = Intent(this, HomeActivity::class.java)
                startActivity(actSwitcher)
            }
            R.id.profile -> {
                val actSwitcher = Intent(this, ProfileActivity::class.java)
                startActivity(actSwitcher)
            }
            R.id.settings -> {
                val actSwitcher = Intent(this, SettingsActivity::class.java)
                startActivity(actSwitcher)
            }
        }
        return true
    }
}