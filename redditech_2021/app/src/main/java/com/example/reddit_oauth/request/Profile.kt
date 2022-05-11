package com.example.reddit_oauth.request

class Profile(
    val is_employee : Boolean,
    val subreddit : SubRedditProfile
)
{
    override fun toString(): String {
        return "Profile{is_employee: " + is_employee + "\n" + "subreddit: " + subreddit + "}\n"
    }
}