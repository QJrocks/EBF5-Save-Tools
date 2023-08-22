// This is an old file initially used for solving the random equipment order for the "random equips" game mode.
// It's a bit messy and doesn't account for a few quirks with the system (such as save-load cycling), but it's important to keep here just as a backup.
// This logic has been entirely reimplemented in a cleaner way in the web page version.
// Investigate this historical artifact at your own peril.

#include <iostream>
#include <vector>

struct LocalizationSet {
    std::vector<std::wstring> english;
};

class EquipSet {
public:
    size_t size;
    //Internally, the game uses string matching for equipment (for example, the Flame Badge's internal ID is "firebadge") and localization. I'm using int IDs into array indices because it's easier for this program and also faster.
    std::vector<bool> equipSelected;
    char seedChar1, seedChar2;
    LocalizationSet localize;

    EquipSet(size_t s, char c1, char c2, LocalizationSet locl) {
        size = s;
        seedChar1 = c1;
        seedChar2 = c2; 
        equipSelected.resize(size);

        for (size_t x = 0; x < size; x++) {
            equipSelected[x] = false;
        }

        localize = locl;
    }

    bool equipsAvailable() {
        for (size_t x = 0; x < size; x++) {
            if (equipSelected[x] == false) {
                return true;
            }
        }
        return false;
    }
};

void printOrder(int fileSeed, EquipSet set) {
    int randSelect = 0;
    int seed = fileSeed + set.seedChar1 + set.seedChar2;
    do
    {
        randSelect = (randSelect += seed + 1) % set.size;
        seed /= 1.1;
        if (!set.equipSelected[randSelect]) {
            std::wcout << set.localize.english[randSelect] << L", ";
            set.equipSelected[randSelect] = true;
        }
    } while (set.equipsAvailable());
    std::cout << std::endl;
}

int main() {
    LocalizationSet swordLocalization;
    LocalizationSet staffLocalization;
    LocalizationSet gunLocalization;
    LocalizationSet bowLocalization;
    LocalizationSet toyLocalization;
    LocalizationSet mHatLocalization;
    LocalizationSet mArmorLocalization;
    LocalizationSet fHatLocalization;
    LocalizationSet fArmorLocalization;
    LocalizationSet flairLocalization;

    //Order of equipment is from internal game files, not the in-game order
    swordLocalization.english = { L"Heaven's Gate", L"Berzerker", L"Inferno", L"Ice Needle", L"Lightning Shard", L"Sapphire Saint", L"Black Fang", L"The Chopper", L"Giant Slayer", L"Hyper Drill", L"Emerald Smasher", L"Devil's Fork", L"Ultra Pro 9000X", L"Club of Withering", L"Crimson Razorback", L"Dragon's Feather", L"Golden Axe", L"Dark Stalker", L"Fusion Blade", L"Soul Eater", L"Love Blade"};
    //Fun fact: The internal array for every staff in the game is called "STALVES".
    staffLocalization.english = { L"Sol Spear", L"Arctic Trident", L"Wrath of Zeus", L"Druid Staff", L"Nimbus Rod", L"Dragon Wings", L"Gigavolt", L"Alchemy Set", L"Kaladanda", L"Wrecking Rod", L"Elder's Wisdom", L"Obsidian Staff", L"Celtic Cross", L"Dark Tooth", L"The Knife", L"Paper Fan", L"Oak Staff", L"Beholding Eye", L"Soul Crusher", L"Shooting Star", L"Slime Staff"};
    gunLocalization.english = { L"Nitro Bomber XL", L"Hellfire Shotgun", L"Thunder Core", L"Deep Blue", L"Chainsaw Gun", L"Vortex Cannon", L"Sub Zero", L"Shadow Blaster", L"Biohazard Blaster", L"Crystal Wing", L"Heavy Claw", L"Soul Pistol", L"Super Snipe ZX", L"Coconut Shooter", L"Flame Titan", L"Heartstopper", L"Gungnir", L"Spine Snapper", L"Desert Scorpion", L"Accelerator", L"Green Goliath" };
    bowLocalization.english = { L"Fairy Bow", L"Cold Steel", L"Thor's Hammer", L"Aquamarine", L"Gaia's Gift", L"Crimson Dragon", L"Iron Tusk", L"Fenrir's Jaw", L"The Deceased", L"Juggernaught", L"Emerald Cyclone", L"Eagle Eye", L"The Stinger", L"Chieftain's Horns", L"Regal Turtle", L"Alchemist's Bow", L"Black Widow", L"Angel Wing", L"Sharanga", L"Earth's Whisper", L"Heaven's Voice" };
    toyLocalization.english = { L"Steel Buckler", L"Bandit Blade", L"Neon Lightbulb", L"Honjo Masamune", L"Riot Shield", L"Leaf Shield", L"Star Hammer", L"Dog Sausage", L"Icecream Sandwich", L"Godly Book", L"Human Skull", L"Blood Bank", L"Viking Buckler", L"Turtle Shell", L"Elven Shield", L"Pixel Popper", L"Book of Spells", L"Power Paw", L"Devil's Sunrise", L"King's Guard", L"Buster Sword" };
    mHatLocalization.english = { L"Captain's Hat", L"Knight's Helmet", L"Horned Helmet", L"Spartan Helmet", L"Genji Helmet", L"Basket Hat", L"Dragon Helmet", L"Army Helmet", L"Officer's Hat", L"Space Helmet", L"Scottish Cap", L"Spelunking Hat", L"Wizard Hat", L"Headband", L"Necromancer's Helmet", L"Cardboard Box", L"Gas Mask", L"Death Mask", L"Puppy Hat", L"Pumpkin Head", L"Santa Hat" };
    mArmorLocalization.english = { L"Captain's Coat", L"Heroic Armor", L"Viking Fur", L"Spartan Cuirass", L"Genji Armor", L"Ninja Gear", L"Dragon Armor", L"Camo Jacket", L"Officer's Coat", L"Space Ace", L"Scottish Kilt", L"Explorer's Jacket", L"Wizard Robe", L"Turtle Gi", L"Flame Suit", L"Hobo Clothes", L"Hipster Shirt", L"Shell Armor", L"Priest's Tunic", L"Coat of Teeth", L"Santa Outfit" };
    //Fun fact: All of the "Bobble" hats are internally spelled "Bauble"! Except for the Spider Bobble. That one is spelled with bobble.
    fHatLocalization.english = { L"Red Ribbon", L"Amber Bobble", L"Nurse Hat", L"Fur Hat", L"Pope Hat", L"Leafy Hairclip", L"Curly Horns", L"Cat Ears", L"Flower Bobble", L"Dark Bobble", L"Slime Bunny", L"Ninja Chopsticks", L"Robot Ears", L"Drill Bits", L"Bunny Ears", L"Ice Shards", L"Royal Crown", L"Rubber Duck", L"Blue Elephant", L"Spider Bobble", L"Holly Hairpin" };
    //Fun fact: The Bubble Dress is internally called the "blue dress". It's not wrong?
    fArmorLocalization.english = { L"Red Dress", L"Ranger Skirt", L"Nurse Uniform", L"Fur Dress", L"Pope Dress", L"Cactus Dress", L"Cow Costume", L"Maid Outfit", L"Summer Kimono", L"Dark Gown", L"Magical Skirt", L"Ninja Skirt", L"Mecha Suit", L"Obsidian Armor", L"School Uniform", L"Bubble Dress", L"Camo Skirt", L"Sami Dress", L"Casual Skirt", L"Spider Gown", L"Santa Skirt" };
    //Fun fact: All the internal names for the earrings flairs are mispelled as "earings" in the game code!
    flairLocalization.english = { L"Flame Badge", L"Lightning Badge", L"Frost Badge", L"Pearl Necklace", L"Surgical Mask", L"Angel Pin", L"Bandage", L"Iron Cross", L"Silver Cross", L"Golden Pendant", L"Battle Paint", L"Lucky Clover", L"Hoop Earings", L"The Tr*force", L"Green Cross", L"Fairy", L"Pocket Watch", L"Agnry Faic", L"Target Badge", L"Balance Badge", L"Tentacle", L"Peace Badge", L"Crossbone Pin", L"Chrome Earrings", L"Amethyst Earrings", L"Emerald Earrings", L"Fat Fly", L"Fake Mustache", L"Big Eyebrows", L"Small Cloud", L"Cat Tail", L"Mini Drone", L"Sword Medal", L"Shield Medal", L"Gold Star", L"Platinum Star", L"Heart Pendant", L"Lucky Fish", L"Coin Charm", L"Juicy Beast", L"The One R*ng", L"Baby Penguin", L"RAM Chip", L"Meow Meow Badge", L"Nano Machines", L"Pixel Glasses", L"Companion C*be", L"Dog Tags", L"Tetromino", L"Captain Viridian", L"Dinosaur Egg", L"Bitey Badge", L"Narutomaki", L"Pet Rock", L"Tooth"};
    
    EquipSet swords = EquipSet(21, 'w', 'o', swordLocalization);
    EquipSet staffs = EquipSet(21, 't', 'a', staffLocalization);
    EquipSet guns = EquipSet(21, 'u', 'n', gunLocalization);
    EquipSet bows = EquipSet(21, 'o', 'w', bowLocalization);
    EquipSet toys = EquipSet(21, 'o', 'y', toyLocalization);
    EquipSet hatsM = EquipSet(21, 'a', 't', mHatLocalization);
    EquipSet armorM = EquipSet(21, 'r', 'm', mArmorLocalization);
    EquipSet hatsF = EquipSet(21, 'a', 't', fHatLocalization);
    EquipSet armorF = EquipSet(21, 'r', 'm', fArmorLocalization);
    EquipSet flairs = EquipSet(55, 'l', 'a', flairLocalization);

    //Hardcoded seed from a sample file I used. The JS version reads in the seed from the file.
    printOrder(58973092, swords);
    printOrder(58973092, staffs);
    printOrder(58973092, guns);
    printOrder(58973092, bows);
    printOrder(58973092, toys);
    printOrder(58973092, hatsM);
    printOrder(58973092, armorM);
    printOrder(58973092, hatsF);
    printOrder(58973092, armorF);
    printOrder(58973092, flairs);
}
