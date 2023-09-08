#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria materias[4];

	public:
		Character();
        Character(std::string const &name);
		~Character();
		Character(const Character &Character);
		Character &operator=(const Character &Character);

		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif