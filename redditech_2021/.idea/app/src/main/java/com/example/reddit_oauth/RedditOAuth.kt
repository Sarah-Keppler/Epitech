package com.example.reddit_oauth

import android.content.Context
import android.content.SharedPreferences
import android.util.Log
import org.json.JSONArray
/*
class RedditOAuth(var context : Context)
{
    var pref : SharedPreferences
    var token : String = ""
    var CLIENT_ID : String = ""
    var CLIENT_SECRET : String = ""
    var BASE_URL : String = ""
    var REDIRECT_URI : String = ""
    var client : AsyncHttpClient = AsyncHttpClient()

    fun get(url : String, params : RequestParams, responseHandler: AsyncHttpResponseHandler) {
        client.get(getAbsoluteUrl(url), params, responseHandler)
    }

    fun post(url : String, params: RequestParams, responseHandler: AsyncHttpResponseHandler) {
        client.post(getAbsoluteUrl(url), params, responseHandler)
    }

    private fun getAbsoluteUrl(relativeUrl : String) : String {
        return BASE_URL + relativeUrl
    }

    fun getToken(relativeUrl: String, grant_type : String, device_id : String) {
        client.setBasicAuth(CLIENT_ID, CLIENT_SECRET)
        pref = context.getSharedPreferences("AppPref", Context.MODE_PRIVATE)
        var code : String? = pref.getString("Code", "")

        var requestParams : RequestParams = RequestParams()
        requestParams.put("code", code)
        requestParams.put("grant_type", grant_type)
        requestParams.put("redirect_uri", REDIRECT_URI)

        var jsonResponseHandler = JsonHttpResponseHandler()
        post(relativeUrl, requestParams, object : JsonHttpResponseHandler() {
            override fun onSuccess(
                statusCode: Int,
                headers: Array<out Header>?,
                response: JSONArray?
            ) {
                Log.i("response", response.toString())
                try {
                    token = response?.getString("access_token")
                    var edit : SharedPreferences.Editor = pref.edit()
                    edit.putString("token", token)
                    edit.commit()
                    Log.i("Access_token", pref)
                }
            }
        })
    }
}

 */

/*
post(relativeUrl, requestParams, new JsonHttpResponseHandler() {
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                // If the response is JSONObject instead of expected JSONArray
                Log.i("response",response.toString());
                try {
                    token = response.getString("access_token").toString();
                    SharedPreferences.Editor edit = pref.edit();
                    edit.putString("token",token);
                    edit.commit();
                    Log.i("Access_token",pref.getString("token",""));
                }catch (JSONException j)
                {
                    j.printStackTrace();
                }

            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                //super.onFailure(statusCode, headers, throwable, errorResponse);
                Log.i("statusCode", "" + statusCode);


            }
        });


public class RedditRestClient {
    SharedPreferences pref;
    String token;
    Context context;
    private static String CLIENT_ID = "YOUR CLIENT_ID";
    private static String CLIENT_SECRET ="";
    private static final String BASE_URL = "https://www.reddit.com/api/v1/";
	private static String REDIRECT_URI="YOUR reddit_uri(as per your reddit app preferences)";
    RedditRestClient(Context cnt){
        context = cnt;
    }
    private static AsyncHttpClient client = new AsyncHttpClient();
    public static void get(String url, RequestParams params, AsyncHttpResponseHandler responseHandler) {
        client.get(getAbsoluteUrl(url), params, responseHandler);}
    public static void post(String url, RequestParams params, AsyncHttpResponseHandler responseHandler) {
        client.post(getAbsoluteUrl(url), params, responseHandler);}
    private static String getAbsoluteUrl(String relativeUrl) {
        return BASE_URL + relativeUrl;
    }

    public void getToken(String relativeUrl,String grant_type,String device_id) throws JSONException {
        client.setBasicAuth(CLIENT_ID,CLIENT_SECRET);
        pref = context.getSharedPreferences("AppPref",Context.MODE_PRIVATE);
        String code =pref.getString("Code", "");

        RequestParams requestParams = new RequestParams();
        requestParams.put("code",code);
        requestParams.put("grant_type",grant_type);
        requestParams.put("redirect_uri", REDIRECT_URI);

        post(relativeUrl, requestParams, new JsonHttpResponseHandler() {
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                // If the response is JSONObject instead of expected JSONArray
                Log.i("response",response.toString());
                try {
                    token = response.getString("access_token").toString();
                    SharedPreferences.Editor edit = pref.edit();
                    edit.putString("token",token);
                    edit.commit();
                    Log.i("Access_token",pref.getString("token",""));
                }catch (JSONException j)
                {
                    j.printStackTrace();
                }

            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                //super.onFailure(statusCode, headers, throwable, errorResponse);
                Log.i("statusCode", "" + statusCode);


            }
        });

    }


    public void revokeToken()
    {
        client.setBasicAuth(CLIENT_ID,CLIENT_SECRET);
        pref = context.getSharedPreferences("AppPref", Context.MODE_PRIVATE);
        String access_token = pref.getString("token","");

        RequestParams requestParams = new RequestParams();
        requestParams.put("token",access_token);
        requestParams.put("token_type_hint","access_token");

        post("revoke_token",requestParams,new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                // If the response is JSONObject instead of expected JSONArray
                Log.i("response", response.toString());
                SharedPreferences.Editor edit = pref.edit();
                edit.remove(token);
                edit.commit();

            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                //super.onFailure(statusCode, headers, throwable, errorResponse);
                Log.i("statusCode", "" + statusCode);
            }
        });
    }

	public void getUsername() {
        Log.i("token", pref.getString("token", ""));
        //  client.addHeader("Authorization", "bearer " + pref.getString("token", ""));
        // client.addHeader("User-Agent", "Redditsavedoffline/0.1 by pratik");

        Header[] headers = new Header[2];
        headers[0] = new BasicHeader("User-Agent", "myRedditapp/0.1 by redditusername");
        headers[1] = new BasicHeader("Authorization", "bearer " + pref.getString("token", ""));

        client.get(context, "https://oauth.reddit.com/api/v1/me", headers, null, new JsonHttpResponseHandler() {

            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                  Log.i("response", response.toString());
                try {
                    String username = response.getString("name").toString();
                    SharedPreferences.Editor edit = pref.edit();
                    edit.putString("username", username);
                    edit.commit();
                } catch (JSONException j) {
                    j.printStackTrace();
                }

            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                Log.i("response", errorResponse.toString());
                Log.i("statusCode", "" + statusCode);
            }
        });
    }

 */