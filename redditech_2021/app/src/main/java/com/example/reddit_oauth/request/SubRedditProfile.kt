package com.example.reddit_oauth.request

class SubRedditProfile(
    val display_Name : String,
    val title : String,
    val description : String,
    val icon_img : String
)
{
    override fun toString(): String {
        return "SubRedditProfile{display_Name: " + display_Name + ",\n\t" +
                "title: " + title + ",\n\t" +
                "description: " + description + ",\n\t" +
                "icon_img: " + icon_img + "}\n"
    }
}