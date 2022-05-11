
package com.epitech.redditech.api

import android.util.Log
import okhttp3.Interceptor
import okhttp3.Response

class RedditInterceptor(val refresh : String) : Interceptor {
    override fun intercept(chain: Interceptor.Chain): Response {
        Log.e("INTERCEPT", "bearer $refresh")
        val request = chain.request()
            .newBuilder()
            .addHeader("Authorization", "bearer $refresh")
            .build()
        return chain.proceed(request)
    }
}

