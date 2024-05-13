#include <string>
#include <iostream>
std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

class Player {
public:
	std::string name = gen_random(10);
	float speed = 6;
	int health = 100;
	const int healthmax = 100;

	void GetHealth() {
		std::cout << name << " current health: " << health << "\n";
		return;
	}
	void Damage(int damage)
	{
		health -= damage;
		std::cout << name << " demaged by: " << damage << "\n";
		return;
	}
	void Heal(int healammount)
	{
		if (health == healthmax)
			return;
		else if (health <= healthmax) 
		{
			if (health + healammount > healthmax)
			{
				health = 100;
				std::cout << name << " health is cuurent: " << health << "\n";
			}
			else
			{
				health += healammount;
				std::cout << name << " healed by: " << healammount << " health amout now: " << health << "\n";
			}
		}
		return;
	}
};