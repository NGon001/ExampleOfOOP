#include "CustomLibrary.hpp"
void Damageplayer(Player &player, int damage)
{
    player.GetHealth();
    player.Damage(damage);
    player.GetHealth();
}

void ServerSendChatMessage(std::string messaage)
{
    std::cout << messaage << "\n";
}
int main()
{
    Player player[30];
    for (int i = 0; i < 30; i++)
    {
        //std::string message = "";
        ServerSendChatMessage(player[i].name + " Was connected to the server.");
    }
    for (int i = 0; i < 30; i++)
    {
        if (i <= 29)
        {
            Damageplayer(player[i++], 10);
        }    
    }
    for (int i = 0; i < 30; i++)
    {
        player[i].Heal(10);
    }
    ServerSendChatMessage("Program was stop");
    //std::cout << "Hello World!\n";
}
