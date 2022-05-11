using System;
using System.Collections.Generic;
using System.Text;
using DSharpPlus.CommandsNext;
using System.Threading.Tasks;
using DSharpPlus.CommandsNext.Attributes;
using DSharpPlus.Entities;
using DSharpPlus.Interactivity.Extensions;

namespace Discord_Bot.Commands
{
    public class ReactCommand : BaseCommandModule
    {
        [Command("join")]
        public async Task Join(CommandContext ctx)
        {
            DiscordEmbedBuilder joinEmbed = new DiscordEmbedBuilder
            {
                Title = "Would you like to join?",
                ImageUrl = ctx.Client.CurrentUser.AvatarUrl,
                Color = DiscordColor.Green
            };
            
            var message = await ctx.Channel.SendMessageAsync(embed: joinEmbed).ConfigureAwait(false);

            var joinEmojiOK = DiscordEmoji.FromName(ctx.Client, ":+1:");
            var joinEmojiNO = DiscordEmoji.FromName(ctx.Client, ":-1:");

            await message.CreateReactionAsync(joinEmojiOK).ConfigureAwait(false);
            await message.CreateReactionAsync(joinEmojiNO).ConfigureAwait(false);

            var interactivity = ctx.Client.GetInteractivity();

            var reactionResult = await interactivity.WaitForReactionAsync(
                x => x.Message == message &&
                x.User == ctx.User &&
                (x.Emoji == joinEmojiOK || x.Emoji == joinEmojiNO)).ConfigureAwait(false);

            if (reactionResult.Result.Emoji == joinEmojiOK)
            {
                var role = ctx.Guild.GetRole(958676643185045534);
                await ctx.Member.GrantRoleAsync(role).ConfigureAwait(false);
            }

            await message.DeleteAsync().ConfigureAwait(false);
        }
    }
}
