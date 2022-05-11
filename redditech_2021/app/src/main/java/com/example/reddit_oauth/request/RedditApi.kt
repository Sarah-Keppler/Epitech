package com.example.reddit_oauth.request

import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Header
import retrofit2.http.Path
import retrofit2.http.Query

interface RedditApi {
    @GET("./top.json")
    fun getTop() : Call<Page>
    @GET("./best.json")
    fun getNew() : Call<Page>
    @GET("./hot.json")
    fun getHot() : Call<Page>

    //@GET("./r/zelda/.json")
    @GET("r/{search}/.json")
    //fun getSearch() : Call<Page>
    fun getSearch(@Path("search") search : String) : Call<Page>

    @GET("api/v1/me")
    fun getMe(
        @Header("Authorization") authorization : String
    ) : Call<Profile>
}