package com.example.reddit_oauth.request

import android.content.ContentValues.TAG
import android.content.Context
import android.nfc.Tag
import android.util.Log
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.epitech.redditech.api.RedditInterceptor
import com.example.reddit_oauth.R
import com.example.reddit_oauth.adapter.PostAdapter
import okhttp3.OkHttpClient
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory

class NewRequest(val context : Context, val recyclerView: RecyclerView) {
    val retrofit : Retrofit = Retrofit.Builder()
        .baseUrl("https://www.reddit.com")
        .addConverterFactory(GsonConverterFactory.create())
        .build()
    val redditApi : RedditApi = retrofit.create(RedditApi::class.java)

    fun getTop() {
        var call = redditApi.getTop()
        call.enqueue(object : Callback<Page> {
            override fun onResponse(call: Call<Page>, response: Response<Page>) {
                if (!response.isSuccessful) {
                    Toast.makeText(context, "Code: " + response.code(), Toast.LENGTH_SHORT)
                    return
                }
                var page = response.body()
                val list : MutableList<ChildData> = arrayListOf()
                for (child : Child in page!!.data.children)
                    list.add(child.data)
                recyclerView.adapter = PostAdapter(context, list)
            }

            override fun onFailure(call: Call<Page>, t: Throwable) {
                Toast.makeText(context, t.message, Toast.LENGTH_SHORT)
            }
        })
    }

    fun getHot() {
        var call = redditApi.getHot()
        call.enqueue(object : Callback<Page> {
            override fun onResponse(call: Call<Page>, response: Response<Page>) {
                if (!response.isSuccessful) {
                    Toast.makeText(context, "Code: " + response.code(), Toast.LENGTH_SHORT)
                    return
                }
                var page = response.body()
                val list : MutableList<ChildData> = arrayListOf()
                for (child : Child in page!!.data.children)
                    list.add(child.data)
                recyclerView.adapter = PostAdapter(context, list)
            }

            override fun onFailure(call: Call<Page>, t: Throwable) {
                Toast.makeText(context, t.message, Toast.LENGTH_SHORT)
            }
        })
    }

    fun getNew() {
        var call = redditApi.getNew()
        call.enqueue(object : Callback<Page> {
            override fun onResponse(call: Call<Page>, response: Response<Page>) {
                if (!response.isSuccessful) {
                    Toast.makeText(context, "Code: " + response.code(), Toast.LENGTH_SHORT)
                    return
                }
                var page = response.body()
                val list : MutableList<ChildData> = arrayListOf()
                for (child : Child in page!!.data.children)
                    list.add(child.data)
                recyclerView.adapter = PostAdapter(context, list)
            }

            override fun onFailure(call: Call<Page>, t: Throwable) {
                Toast.makeText(context, t.message, Toast.LENGTH_SHORT)
            }
        })
    }

    fun getSearch(search : String) {
        var call = redditApi.getSearch(search)
        //var call = redditApi.getSearch()
        call.enqueue(object : Callback<Page> {
            override fun onResponse(call: Call<Page>, response: Response<Page>) {
                Log.e(TAG, "Code: " + response.code())
                if (!response.isSuccessful) {
                    Toast.makeText(context, "Code: " + response.code(), Toast.LENGTH_SHORT)
                    return
                }
                var page = response.body()
                val list : MutableList<ChildData> = arrayListOf()
                for (child : Child in page!!.data.children)
                    list.add(child.data)
                recyclerView.adapter = PostAdapter(context, list)
            }

            override fun onFailure(call: Call<Page>, t: Throwable) {
                Log.e(TAG, "Code failed: " + t.message)
                Toast.makeText(context, t.message, Toast.LENGTH_SHORT)
            }
        })
    }
}