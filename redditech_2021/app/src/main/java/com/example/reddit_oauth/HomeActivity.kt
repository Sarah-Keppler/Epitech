package com.example.reddit_oauth

import android.content.ContentValues.TAG
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.recyclerview.widget.RecyclerView
import com.epitech.redditech.api.RedditInterceptor
import com.example.reddit_oauth.adapter.PostAdapter
import com.example.reddit_oauth.menu.MainMenuActivity
import com.example.reddit_oauth.request.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import okhttp3.OkHttpClient

class HomeActivity : MainMenuActivity() {
    private lateinit var request : NewRequest
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.home_activity)
        val toolbar: Toolbar = findViewById<View>(R.id.toolbar) as Toolbar
        setSupportActionBar(toolbar)

        val recyclerView = findViewById<RecyclerView>(R.id.recycler_view)
        request = NewRequest(applicationContext, recyclerView)
        request.getHot()

            /*
        var access : TextView = findViewById(R.id.textView2)
        var refresh : TextView = findViewById(R.id.textView3)
        access.setText(intent.getStringExtra("access"))
        refresh.setText(intent.getStringExtra("refresh"))*/

        //getBest()
    /*
        val retrofit : Retrofit = Retrofit.Builder()
            .baseUrl("https://www.reddit.com")
            .addConverterFactory(GsonConverterFactory.create())
            .build()
        var redditApi : RedditApi = retrofit.create(RedditApi::class.java)
        var call = redditApi.getTop()
        call.enqueue(object : Callback<Page> {
            override fun onResponse(call: Call<Page>, response: Response<Page>) {
                if (!response.isSuccessful) {
                    Toast.makeText(applicationContext, "Code: " + response.code(), Toast.LENGTH_SHORT)
                    return
                }
                var page = response.body()
                val list : MutableList<ChildData> = arrayListOf()
                for (child : Child in page!!.data.children)
                    list.add(child.data)
                val recyclerView = findViewById<RecyclerView>(R.id.recycler_view)
                recyclerView.adapter = PostAdapter(applicationContext, list)
            }

            override fun onFailure(call: Call<Page>, t: Throwable) {
                Toast.makeText(applicationContext, t.message, Toast.LENGTH_SHORT)
            }
        })
        */
    }

    fun getHot(view : View) {
        request.getHot()
    }

    fun getTop(view : View) {
        request.getTop()
    }

    fun getNew(view : View) {
        request.getNew()
    }

    fun getSearch(view : View) {
        val editText : EditText = findViewById(R.id.editText)
        val search : String = editText.text.toString()
        Log.e(TAG, "Search: " + search)
        if (!search.equals("")) {
            request.getSearch(search)
        }
    }
}