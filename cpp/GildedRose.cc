#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items)
{
}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items))
{
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        std::string nameOne = "Aged Brie";
        std::string nameTwo = "Backstage passes to a TAFKAL80ETC concert";
        std::string nameThree = "Sulfuras, Hand of Ragnaros";

        if (items[i].name != nameOne && items[i].name != nameTwo && items[i].quality > 0 && items[i].name != nameThree)
        {
            items[i].quality--;
        }
        else if (items[i].quality < 50)
        {
            items[i].quality++;
            if (items[i].name == nameTwo)
            {
                if (items[i].sellIn < 6)
                {
                    items[i].quality++;
                }
                if (items[i].sellIn < 11)
                {
                    items[i].quality++;
                }
            }
        }
        if (items[i].name != nameThree)
        {
            items[i].sellIn--;
        }
        if (items[i].sellIn < 0)
        {
            if (items[i].name != nameOne && items[i].name != nameTwo && items[i].quality > 0 && items[i].name != nameThree)
            {
                items[i].quality--;
            }
            if (items[i].name == nameTwo)
            {
                items[i].quality = 0;
            }
            if (items[i].name == nameOne && items[i].quality < 50)
            {
                items[i].quality++;
            }
        }
    }
}
