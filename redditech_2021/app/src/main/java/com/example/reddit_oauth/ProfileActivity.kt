package com.example.reddit_oauth

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import com.example.reddit_oauth.menu.MainMenuActivity
import com.example.reddit_oauth.request.NewRequest
import com.example.reddit_oauth.request.Profile
import com.example.reddit_oauth.request.RedditApi
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

class ProfileActivity : MainMenuActivity() {
    private lateinit var request : NewRequest
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.profile_activity)
        val toolbar : Toolbar = findViewById(R.id.toolbar)
        setSupportActionBar(toolbar)

        val textViewResult : TextView = findViewById(R.id.text_view_result)

        val retrofit : Retrofit = Retrofit.Builder()
            .baseUrl("https://www.reddit.com")
            .addConverterFactory(GsonConverterFactory.create())
            .build()
        var redditApi : RedditApi = retrofit.create(RedditApi::class.java)
        var call = redditApi.getMe(Constant.access)
        call.enqueue(object : Callback<Profile> {
            override fun onResponse(call: Call<Profile>, response: Response<Profile>) {
                if (!response.isSuccessful) {
                    textViewResult.setText("Code: " + response.code())
                    return
                }
                var page = response.body()
                var content : String = "SubReddit: " + page?.subreddit.toString() + "\n"
                textViewResult.setText(content)
            }

            override fun onFailure(call: Call<Profile>, t: Throwable) {
                textViewResult.setText(t.message)
            }
        })
    }
}