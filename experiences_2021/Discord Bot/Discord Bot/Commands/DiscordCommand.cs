using System;
using System.Collections.Generic;
using System.Text;
using DSharpPlus.CommandsNext;
using System.Threading.Tasks;
using DSharpPlus.CommandsNext.Attributes;

namespace Discord_Bot.Commands
{
    public class DiscordCommand : BaseCommandModule
    {
        [Command("ping")]
        public async Task Ping(CommandContext ctx)
        {
            await ctx.Channel.SendMessageAsync("Pong").ConfigureAwait(false);
        }

        [Command("help")]
        public async Task Help(CommandContext ctx)
        {
            await ctx.Channel.SendMessageAsync("**Commands available**: ping and join").ConfigureAwait(false);
        }
    }
}
