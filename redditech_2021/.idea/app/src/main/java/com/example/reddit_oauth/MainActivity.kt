package com.example.reddit_oauth

import android.content.ContentValues.TAG
import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Base64
import android.util.Log
import android.view.View
import android.widget.TextView
import android.widget.Toast
import okhttp3.*
import okhttp3.MediaType.Companion.toMediaTypeOrNull
import okhttp3.RequestBody.Companion.toRequestBody
import org.json.JSONException
import org.json.JSONObject
import java.io.IOException

class MainActivity : AppCompatActivity() {
    //private val AUTH_URL : String = "https://www.reddit.com/api/v1/authorize?client_id=b4drOIQ_MT2riC_wHsNx9w&response_type=code&state=RANDOM_STRING&redirect_uri=http://localhost:8080&duration=permanent&scope=*"
    private val AUTH_URL : String = "https://www.reddit.com/api/v1/authorize?client_id=%s&response_type=code&state=%s&redirect_uri=%s&duration=permanent&scope=*"
    private val CLIENT_ID : String = "b4drOIQ_MT2riC_wHsNx9w"
    private val STATE : String = "RANDOM_STRING"
    private val REDIRECT_URI : String = "http://localhost:8080"
    //private val ACCESS_TOKEN_URL : String = "https://www.reddit.com/api/v1/access_token?grant_type=authorization_code&code=72ctO51F0XIVk2GchqoFqx5zWn5qCQ&redirect_uri=http://localhost:8080"
    private val ACCESS_TOKEN_URL : String = "https://www.reddit.com/api/v1/access_token"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //goHome("access", "refresh")
        //val actSwitcher = Intent(this, HomeActivity::class.java)
        //startActivity(actSwitcher)
    }

    fun goHome(access : String, refresh : String) {
        Log.d(TAG, "Access Token = $access")
        Log.d(TAG, "Refresh Token = $refresh")
        val actSwitcher = Intent(this, HomeActivity::class.java)
        actSwitcher.putExtra("access", access)
        actSwitcher.putExtra("refresh", refresh)
        Constant.access = access
        Constant.refresh = refresh
        startActivity(actSwitcher)
    }

    fun startSignIn(view : View) {
        // actSwitcher = Intent(this, HomeActivity::class.java)
        //startActivity(actSwitcher)
        val url : String = String.format(AUTH_URL, CLIENT_ID, STATE, REDIRECT_URI)
        val intent : Intent = Intent(Intent.ACTION_VIEW, Uri.parse(url))
        startActivity(intent)
    }

    override fun onResume() {
        super.onResume()

        if (intent != null && intent.action.equals(Intent.ACTION_VIEW)) {
            val uri : Uri? = intent.data
            if (uri?.getQueryParameter("error") != null) {
                val error : String? = uri.getQueryParameter("error")
                Log.e(TAG, "An error has occured: " + error)
            } else {
                val state : String? = uri?.getQueryParameter("state")
                if (state.equals(STATE)) {
                    val code : String? = uri?.getQueryParameter("code")
                    getAccessToken(code)
                }
            }
        }
    }

    private fun getAccessToken(code : String?) {
        val client : OkHttpClient = OkHttpClient()
        val authString : String = CLIENT_ID + ":"
        val encodedAuthString : String = Base64.encodeToString(authString.toByteArray(), Base64.NO_WRAP)

        val request : Request = Request.Builder()
            .addHeader("User-Agent", "Sample App")
            .addHeader("Authorization", "Basic " + encodedAuthString)
            .url(ACCESS_TOKEN_URL)
            .post(
                ("grant_type=authorization_code&code=" + code +
                        "&redirect_uri=" + REDIRECT_URI).toRequestBody("application/x-www-form-urlencoded".toMediaTypeOrNull())
            )
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onResponse(call: Call, response: Response) {
                val json : String = response?.body!!.string()
                try {
                    val data : JSONObject = JSONObject(json)
                    val accessToken : String = data.optString("access_token")
                    val refreshToken : String = data.optString("refresh_token")
                    //Toast.makeText(applicationContext, "Access Token = " + accessToken, Toast.LENGTH_SHORT).show()
                    //Toast.makeText(applicationContext, e.message, Toast.LENGTH_SHORT).show()
                    Log.e(TAG, "Access Token = " + accessToken)
                    Log.e(TAG, "Refresh Token = " + refreshToken)
                    goHome(accessToken, refreshToken)
                } catch (e : JSONException) {
                    e.printStackTrace()
                }
            }

            override fun onFailure(call: Call, e: IOException) {
                Toast.makeText(applicationContext, e.message, Toast.LENGTH_SHORT).show()
            }
        })
    }
}