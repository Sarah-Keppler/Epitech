package com.example.reddit_oauth.request

class Page(
    val kind : String,
    val data : Data)
{
    override fun toString(): String {
        return "Page{kind: " + kind + ",\n" +
                "data: " + data + "}\n"
    }
}

class Data(
    val children: List<Child>,
    val after: String?,
    val before: String?)
{
    override fun toString(): String {
        return "Data{\tchildren: \n" + children + ",\n" +
                "\tafter: " + after + ",\n" +
                "\tbefore: " + before + "}\n"
    }
}

class Child(
    val kind : String,
    val data : ChildData)
{
    override fun toString(): String {
        return "\n\tChild{kind: " + kind + ",\n" +
                "\tdata: " + data + "}"
    }
}

class ChildData (
    val author: String,
    val title: String,
    val num_comments: Int,
    val created: Long,
    val thumbnail: String,
    val url: String)
{
    override fun toString(): String {
        return "ChildData{author: " + author + ",\n\t\t" +
                "title: " + title + ",\n\t\t" +
                "num_comments: " + num_comments.toString() + ",\n\t\t" +
                "created: " + created.toString() + ",\n\t\t" +
                "thumbnail: " + thumbnail + ",\n\t\t" +
                "url: " + url + "}\n"
    }
}