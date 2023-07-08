#include <dpp/dpp.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>
#include<random>
#include<locale>
#include<windows.h> 
#include "MyBot.h"
int guess_ans;
int randomNumber[4];
std::string ans1, ans2, ans3, ans4, ans;
const std::string BOT_TOKEN = "MTEyNDY3ODA1NTc0NzY3MDA0Nw.GTZO0p.Un4HOdoXhp2y55zA6ULM_vh4_9___saKCZn1Jk"; //Put your TOKEN here!!
//int64_t guess_ans = 0;

int main() {
    srand(time(NULL));
    
    dpp::cluster bot(BOT_TOKEN);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            //Greeting (6pts)
            dpp::slashcommand greeting("greeting", "Say Hello to the given username", bot.me.id);
            greeting.add_option(dpp::command_option(dpp::co_string, "name", "Please enter the username", true));
            bot.global_command_create(greeting);
            //Add (3pts)
            dpp::slashcommand add("add", "Add two given integers", bot.me.id);
            add.add_option(
                dpp::command_option(dpp::co_string, "number_1", "Please enter an integer", true)
            );
            add.add_option(
                dpp::command_option(dpp::co_string, "number_2", "Please enter an integer", true)
            );
            bot.global_command_create(add);
            //Sub (3pts)
            dpp::slashcommand sub("sub", "Subtract two given integers", bot.me.id);
            sub.add_option(
                dpp::command_option(dpp::co_string, "number_1", "Please enter an integer", true)
            );
            sub.add_option(
                dpp::command_option(dpp::co_string, "number_2", "Please enter an integer", true)
            );
            bot.global_command_create(sub);

            //Mul (3pts)
            dpp::slashcommand mul("mul", "Multiply two given integers", bot.me.id);
            mul.add_option(
                dpp::command_option(dpp::co_string, "number_1", "Please enter an integer", true)
            );
            mul.add_option(
                dpp::command_option(dpp::co_string, "number_2", "Please enter an integer", true)
            );
            bot.global_command_create(mul);
            //Reset (5pts)
            dpp::slashcommand reset("reset", "Randomly generate an integer between 1 to 100", bot.me.id);
            bot.global_command_create(reset);

            //Guess (5pts)
            dpp::slashcommand guess("guess", "Guess a number between 1 to 100", bot.me.id);
            guess.add_option(
                dpp::command_option(dpp::co_string, "guess_num", "Please guess a number between 1 to 100", true)
            );
            bot.global_command_create(guess);
            //Write (5pts)
            dpp::slashcommand write("write", "write a diary", bot.me.id);
            bot.global_command_create(write);
            //Read (5pts)
            dpp::slashcommand read("read", "read a diary", bot.me.id);
            read.add_option(
                dpp::command_option(dpp::co_string, "date", "Please enter diary date", true)
            );
            read.add_option(
                dpp::command_option(dpp::co_string, "username", "Please enter the username", true)
            );
            bot.global_command_create(read);
            //Remove (5pts)
            dpp::slashcommand remove("remove", "remove a dirary from documents", bot.me.id);
            remove.add_option(
                dpp::command_option(dpp::co_string, "date", "The date of the diary to remove", true)
            );
            remove.add_option(
                dpp::command_option(dpp::co_string, "username", "Please enter the username", true)
            );
            bot.global_command_create(remove);
            //接下來，請放上你們的自訂功能
            //abgame
            dpp::slashcommand abgame("abgame", "Game", bot.me.id);
            abgame.add_option(
                dpp::command_option(dpp::co_string, "first_num", "The first num", true)
            );
            abgame.add_option(
                dpp::command_option(dpp::co_string, "second_num", "The second num", true)
            );
            abgame.add_option(
                dpp::command_option(dpp::co_string, "third_num", "The third num", true)
            );
            abgame.add_option(
                dpp::command_option(dpp::co_string, "fourth_num", "The fourth num", true)
            );
            bot.global_command_create(abgame);
            //help diary
            dpp::slashcommand help_diary("help_diary", "Get a manual of this Bot!!", bot.me.id);
            bot.global_command_create(help_diary);
            //reset3a2b
            dpp::slashcommand reset3a2b("reset3a2b", "Randomly generate 3A2B", bot.me.id);
            bot.global_command_create(reset3a2b);
            //Ansofab (5pts)
            dpp::slashcommand answer_ab("answer_ab", "Give the ans of 3A2B", bot.me.id);
            bot.global_command_create(answer_ab);
            //Ansofguess (5pts)
            dpp::slashcommand answer_guess("answer_guess", "Give the ans of Guess Num", bot.me.id);
            bot.global_command_create(answer_guess);
        }   
       });

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        //Greeting (5pts)
        if (event.command.get_command_name() == "greeting") {
            //string s;
            std::string name = std::get<std::string>(event.get_parameter("name"));
            event.reply("Welcome to Sprout "+name);
        }
        //Add (5pts)
        if (event.command.get_command_name() == "add") {
            std::string n1 = std::get<std::string>(event.get_parameter("number_1"));
            std::string n2 = std::get<std::string>(event.get_parameter("number_2"));
            int num1, num2;
            num1 = std::stoi(n1); num2 = std::stoi(n2);
            std::string ans = std::to_string(num1 + num2);
            event.reply("[Add] The result is " + n1 + " + " + n2 + " = " + ans);
        }
        
        //Sub (5pts)
        if (event.command.get_command_name() == "sub") {
            std::string n1 = std::get<std::string>(event.get_parameter("number_1"));
            std::string n2 = std::get<std::string>(event.get_parameter("number_2"));

            int num1, num2;
            num1 = std::stoi(n1); num2 = std::stoi(n2);
            std::string ans = std::to_string(num1 - num2);
            event.reply("[Sub] The result is " + n1 + " - " + n2 + " = " + ans);
        }
        
        //Mul (5pts)
        if (event.command.get_command_name() == "mul") {
            std::string n1 = std::get<std::string>(event.get_parameter("number_1"));
            std::string n2 = std::get<std::string>(event.get_parameter("number_2"));

            int num1, num2;
            num1 = std::stoi(n1); num2 = std::stoi(n2);
            std::string ans = std::to_string(num1 * num2);
            event.reply("[Mul] The result is " + n1 + " * " + n2 + " = " + ans);
            
        }
        
        //Reset (5pts)
        if (event.command.get_command_name() == "reset") 
        {
            guess_ans = rand() % 100;
            std::string ans = std::to_string(guess_ans);
            event.reply("Reset successful! "+ans);
        }
        //Guess ans
        if (event.command.get_command_name() == "answer_guess")
        {
            event.reply("Reset successful! " + ans);
        }
        //Guess (5pts)
        if (event.command.get_command_name() == "guess") 
        {
            std::string guessing = std::get<std::string>(event.get_parameter("guess_num"));
            int gue = std::stoi(guessing);
            if (gue == guess_ans) 
            {
                std::string gus = std::to_string(guess_ans);
                event.reply("Bingo! the Answer is "+gus);
            }
            else if (gue < guess_ans) 
            {
                std::string gus = std::to_string(gue);
                event.reply("Your Guess is "+gus+" Guess a bigger one");
            }
            else 
            {// gue > guess_ans
                std::string gus = std::to_string(gue);
                event.reply("Your Guess is "+gus+" Guess a smaller one");
            }
        }
        
        //Write (5pts)
        if (event.command.get_command_name() == "write") {
            dpp::interaction_modal_response modal("my_modal", "Please enter stuff");
            //  Add a text component 
            modal.add_component(
                dpp::component().
                set_label("DATE (IN FORMS OF YYYYMMDD)").
                set_id("date").
                set_type(dpp::cot_text).

                set_min_length(5).
                set_max_length(50).
                set_text_style(dpp::text_short)
            );
            modal.add_row();
            modal.add_component(
            dpp::component().
                set_label("USername").
                set_id("username").
                set_type(dpp::cot_text).

                set_min_length(1).
                set_max_length(50).
                set_text_style(dpp::text_short)
            );
            modal.add_row();
            modal.add_component(
                dpp::component().
                set_label("TITLE").
                set_id("title").
                set_type(dpp::cot_text).

                set_min_length(5).
                set_max_length(50).
                set_text_style(dpp::text_short)
            );
            modal.add_row();

            modal.add_component(
                dpp::component().
                set_label("YOUR DIARY").
                set_id("text").
                set_type(dpp::cot_text).

                set_min_length(1).
                set_max_length(2000).
                set_text_style(dpp::text_paragraph)
            );
            // Trigger the dialog box. All dialog boxes are ephemeral 
            event.dialog(modal);

        }
        //Read (5pts)
        if (event.command.get_command_name() == "read") {
            std::string date = std::get<std::string>(event.get_parameter("date"));
            std::string username = std::get<std::string>(event.get_parameter("username"));
            std::ifstream in(date +username+ ".txt");
            if (in) {
                std::string title, line, contents = "";
                std::string ignore;
                in >> ignore >> ignore >> ignore;
                std::getline(in, title);
                in >> ignore;
                while (!in.eof()) {
                    std::getline(in, line);
                    contents += line;
                    contents += '\n';
            }
         //--------------------
                dpp::embed embed = dpp::embed().

                    set_color(dpp::colors::sti_blue).
                    set_title(title).
                    add_field(
                        "Date",
                        date
                    ).
                    add_field(
                        "Content",
                        contents
                    ).
                    set_footer(dpp::embed_footer().set_text("My Diary at " + date)).
                    set_timestamp(time(0));

                in.close();

                dpp::message m;
                m.add_embed(embed);
                //so the message is just an embed
                event.reply(m);
            }
            else {

                event.reply("Diary on " + date + " not found!!!!");
            }
        }
        //-------------------
        //Remove (5pts)
        if (event.command.get_command_name() == "remove") {
            //to do
            std::string date = std::get<std::string>(event.get_parameter("date"));
            std::string  username = std::get<std::string>(event.get_parameter("username"));
            std::string filename = date +username+ ".txt";
            if (std::remove(filename.c_str()) == 0) {//std::string cannot be in remove()
                event.reply("Successfully removed diary at " + date);
            }
            else {
                event.reply("Failed to remove diary at " + date);
            }
        }
        //reset ab
        if (event.command.get_command_name() == "reset3a2b")
        {
            for (int i = 0; i < 4; i++)
            {
                randomNumber[i] = rand() % 10;
            }
            std::string ans1 = std::to_string(randomNumber[0]);
            std::string ans2 = std::to_string(randomNumber[1]);
            std::string ans3 = std::to_string(randomNumber[2]);
            std::string ans4 = std::to_string(randomNumber[3]);
            event.reply("Reset successful!"+ans1+ans2+ans3+ans4);
        }
        //ans ab
        if (event.command.get_command_name() == "answer_ab")
        {
            event.reply("The answer is " + ans1 + ans2 + ans3 + ans4);
        }
        //ab game
        if (event.command.get_command_name() == "abgame")
        {
            int userGuess[4];
            std::string num1 = std::get<std::string>(event.get_parameter("first_num"));
            std::string num2 = std::get<std::string>(event.get_parameter("second_num"));
            std::string num3 = std::get<std::string>(event.get_parameter("third_num"));
            std::string num4 = std::get<std::string>(event.get_parameter("fourth_num"));
            userGuess[0] = std::stoi(num1);
            userGuess[1] = std::stoi(num2);
            userGuess[2] = std::stoi(num3);
            userGuess[3] = std::stoi(num4);
            int right_1 = 0, right_2 = 0, right_3 = 0, right_4 = 0;
            int correctDigits = 0, misplacedDigits = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (randomNumber[i] == userGuess[i])
                {
                    ++correctDigits;
                }
                else
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (randomNumber[i] == userGuess[j])
                        {
                            ++misplacedDigits;
                            break;
                        }
                    }
                }
            }
            std::string ansa = std::to_string(correctDigits);
            std::string ansb = std::to_string(misplacedDigits);
            if (correctDigits == 4) { event.reply("Bingo!! You Win"); }
            else { event.reply("You get " + ansa + " A and " + ansb + "B"); }
            //event.reply("in");
        }
        if (event.command.get_command_name() == "help_diary")
        {
            //event.reply("in");
            dpp::message m("this text has a select menu");
            //event.reply(m);
            m.add_component(
                dpp::component().add_component(
                    dpp::component().set_type(dpp::cot_selectmenu).
                    set_placeholder("Pick something").
                    add_select_option(dpp::select_option("Write", "Write->Write a diary!!").set_emoji(u8"🥹")).
                    add_select_option(dpp::select_option("Read", "Read->Read a diary you written before!!").set_emoji(u8"😄")).
                    add_select_option(dpp::select_option("Remove", "Remove->Remove a diary you written before!!").set_emoji(u8"🤑")).
                    add_select_option(dpp::select_option("Reset", "Reset->Reset the game of Guess Num!!").set_emoji(u8"🤓")).
                    add_select_option(dpp::select_option("Guess", "Guess->Guess an play the game Guess Num!!").set_emoji(u8"😎")).
                    add_select_option(dpp::select_option("Reset3A2B", "Reset3A2B->Reset the game of 3A2B!!").set_emoji(u8"🤪")).
                    add_select_option(dpp::select_option("ABGAME", "ABGAME->Enter 4 int and play the game 3A2B!!").set_emoji(u8"🥳")).
                    set_id("myselid")
                )
            );
            bot.message_create(m);
            event.reply(m);
        }
        });
        bot.on_select_click([&bot](const dpp::select_click_t& event) {
            //Select clicks are still interactions, and must be replied to in some form to
            //prevent the "this interaction has failed" message from Discord to the user.
            event.reply("Whish You Understand " + event.values[0]);
            });
        bot.on_form_submit([&](const dpp::form_submit_t& event) {
            // For this simple example we know the first element of the first row ([0][0]) is value type string.
             // In the real world it may not be safe to make such assumptions!//comment from example program
            std::string date = std::get<std::string>(event.components[0].components[0].value);
            std::string username = std::get<std::string>(event.components[1].components[0].value);
            std::string title = std::get<std::string>(event.components[2].components[0].value);
            std::string content = std::get<std::string>(event.components[3].components[0].value);
            dpp::message m;
            std::string res;
            res = "Date: " + date + '\n' + "Username: "+username+'\n'+"Title: " + title + '\n' + "Content: " + '\n' + content;
            m.set_content(res).set_flags(dpp::m_ephemeral);
            //Emit a reply. Form submission is still an interaction and must generate some form of reply! 
            event.reply(m);
            std::ofstream out(date +username+ ".txt");
            out << res;
            out.close();
            });

        
    /* Start bot */
    bot.start(dpp::st_wait);
    //return 0;
}