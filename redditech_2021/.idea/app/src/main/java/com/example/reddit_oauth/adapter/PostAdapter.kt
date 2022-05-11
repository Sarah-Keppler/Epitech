package com.example.reddit_oauth.adapter

import android.content.Context
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.graphics.drawable.Drawable
import android.media.Image
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.reddit_oauth.R
import com.example.reddit_oauth.request.ChildData
import com.nostra13.universalimageloader.cache.memory.impl.WeakMemoryCache
import java.io.InputStream
import java.lang.Exception
import java.net.URL
import com.nostra13.universalimageloader.core.DisplayImageOptions;
import com.nostra13.universalimageloader.core.ImageLoader;
import com.nostra13.universalimageloader.core.ImageLoaderConfiguration

class PostAdapter (
    private val context : Context,
    private val dataset : List<ChildData>
) : RecyclerView.Adapter<PostAdapter.PostViewHolder>()
{
    class PostViewHolder(private val view: View): RecyclerView.ViewHolder(view) {
        val authorView : TextView = view.findViewById(R.id.item_author)
        val titleView : TextView = view.findViewById(R.id.item_title)
        val imageView: ImageView = view.findViewById(R.id.item_image)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PostViewHolder {
        val adapterLayout = LayoutInflater.from(parent.context)
            .inflate(R.layout.image_post, parent, false)

        return PostViewHolder(adapterLayout)
    }

    override fun onBindViewHolder(holder: PostViewHolder, position: Int) {
        val item = dataset[position]
        holder.authorView.text = item.author
        holder.titleView.text = item.title
        val defaultImage : Int = context.resources.getIdentifier("@drawable/reddit", null, context.packageName)
        val options : DisplayImageOptions = DisplayImageOptions.Builder().cacheInMemory(true)
            .cacheOnDisc(true).resetViewBeforeLoading(true)
            .showImageForEmptyUri(defaultImage)
            .showImageOnFail(defaultImage)
            .showImageOnLoading(defaultImage).build()
        val config : ImageLoaderConfiguration = ImageLoaderConfiguration.Builder(context)
            .defaultDisplayImageOptions(options)
            .memoryCache(WeakMemoryCache()).build()
        ImageLoader.getInstance().init(config)
        val imageLoader : ImageLoader = ImageLoader.getInstance()
        imageLoader.displayImage(item.thumbnail, holder.imageView, options)
    }

    override fun getItemCount() = dataset.size
}