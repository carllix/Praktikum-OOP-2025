#include "PetShelter.hpp"

/* Default constructor:
 * - Creates a shelter with the given name.
 * - Default capacity: 8 dogs, 12 cats.
 * - No pets in the shelter initially.
 */
template <typename T>
PetShelter<T>::PetShelter(std::string shelterName)
{
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        pets[i] = nullptr;
    }
}

/* Constructor with specified capacities:
 * - Creates a shelter with custom capacities for dogs and cats.
 * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
 *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
 */
template <typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity)
{
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        pets[i] = nullptr;
    }

    int totalCapacity = dogCapacity + catCapacity;
    if (totalCapacity > MAX_SHELTER_CAPACITY)
    {
        std::cout << "The total capacity you construct is " << totalCapacity << ", meanwhile the shelter capacity is 20" << std::endl;
    }
}

/* Destructor:
 * - Cleans up all dynamically allocated pets.
 * - Sets pet pointers to nullptr after deletion.
 */
template <typename T>
PetShelter<T>::~PetShelter()
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            delete pets[i];
            pets[i] = nullptr;
        }
    }
}

/* Returns the name of the shelter.
 * Output: Shelter name as a string.
 */
template <typename T>
std::string PetShelter<T>::getShelterName() const
{
    return shelterName;
}

/* Adds a pet to the shelter.
 * Input:
 * - petName: Name of the pet.
 * - age: Age of the pet in years.
 * - isDog: If true, adds a dog; if false, adds a cat.
 * - extraInfo: For dogs, this is the breed; for cats, this is the color.
 *
 * Process:
 * - If shelter is full, prints "Error: Shelter is at full capacity!".
 * - If dog capacity is full, prints "Error: No space for more dogs!".
 * - If cat capacity is full, prints "Error: No space for more cats!".
 *
 * - If addition is successful, system will create a **unique pet ID** based on pet type:
 *   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
 *   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
 *
 * - If addition is successful, prints:
 *   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
 */
template <typename T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo)
{
    if (petCount >= MAX_SHELTER_CAPACITY)
    {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }

    if (isDog && currentDogs >= dogCapacity)
    {
        std::cout << "Error: No space for more dogs!" << std::endl;
        return;
    }

    if (!isDog && currentCats >= catCapacity)
    {
        std::cout << "Error: No space for more cats!" << std::endl;
        return;
    }

    int emptySlot = -1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] == nullptr)
        {
            emptySlot = i;
            break;
        }
    }

    if (emptySlot == -1)
    {
        std::cout << "Error: No available slot found!" << std::endl;
        return;
    }

    Pet *newPet = nullptr;
    std::string petID;

    if (isDog)
    {
        newPet = new Dog(petName, age, extraInfo);
        currentDogs++;
        petID = "D" + std::to_string(currentDogs);
    }
    else
    {
        newPet = new Cat(petName, age, extraInfo);
        currentCats++;
        petID = "C" + std::to_string(currentCats);
    }

    newPet->setId(petID);
    pets[emptySlot] = newPet;
    petCount++;

    std::cout << "Success: " << petName << " has been added as a ";
    if (isDog)
    {
        std::cout << "Dog";
    }
    else
    {
        std::cout << "Cat";
    }
    std::cout << "! Pet ID: " << petID << std::endl;
}
/* Checks if a pet with the given ID exists in the shelter.
 * Input:
 * - petID: ID of the pet to check.
 *
 * Output:
 * - If found, prints pet details using the displayInfo() method.
 * - If not found, prints "Pet ID is invalid!".
 * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
 */
template <typename T>
T *PetShelter<T>::findPet(const std::string &petID) const
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr && pets[i]->getId() == petID)
        {
            pets[i]->displayInfo();
            return dynamic_cast<T *>(pets[i]);
        }
    }

    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}

/* Displays a list of all pets in the shelter.
 * Output:
 * - If no pets in the shelter, prints "No pets in the shelter yet!".
 * - If pets exist, prints in the format:
 *   "<number>. <pet.displayInfo()>"
 *
 * - Numbering in output starts from 1.
 */
template <typename T>
void PetShelter<T>::listAllPets() const
{
    if (petCount == 0)
    {
        std::cout << "No pets in the shelter yet!" << std::endl;
        return;
    }

    int counter = 1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            std::cout << counter << ". ";
            pets[i]->displayInfo();
            counter++;
        }
    }
}

/* Calculates total cost of maintaining all pets in the shelter.
 * - Dogs cost 75 per day.
 * - Cats cost 60 per day.
 *
 * Output: Total daily maintenance cost as an integer.
 * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat)
 * to apply the correct maintenance cost.
 * Example:
 *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
 *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
 */
template <typename T>
int PetShelter<T>::calculateCost() const
{
    int totalCost = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            if (dynamic_cast<Dog *>(pets[i]))
            {
                totalCost += 75;
            }
            else if (dynamic_cast<Cat *>(pets[i]))
            {
                totalCost += 60;
            }
        }
    }

    return totalCost;
}

/* Removes a pet with the given ID from the shelter.
 * Input:
 * - petID: ID of the pet to remove.
 *
 * Output:
 * - If found and removed, prints "<petName> has been removed from the shelter."
 * - If not found, prints "Pet ID is invalid!"
 * Note: Uses dynamic_cast to determine pet type when updating counters:
 *   if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
 *   else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
 */
template <typename T>
void PetShelter<T>::removePet(const std::string &petID)
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr && pets[i]->getId() == petID)
        {
            std::string petName = pets[i]->getName();

            if (dynamic_cast<Dog *>(pets[i]))
            {
                currentDogs--;
            }
            else if (dynamic_cast<Cat *>(pets[i]))
            {
                currentCats--;
            }

            delete pets[i];
            pets[i] = nullptr;
            petCount--;

            std::cout << petName << " has been removed from the shelter." << std::endl;
            return;
        }
    }

    std::cout << "Pet ID is invalid!" << std::endl;
}

template class PetShelter<Pet>;