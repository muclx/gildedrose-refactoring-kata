#include "GildedRose.h"
#include <string>

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
        int qualityItems = items[i].quality;
        int sellInItems = items[i].sellIn;
        std::string nameItems = items[i].name;

        if (nameItems != nameOne && nameItems != nameTwo && qualityItems > 0 && nameItems != nameThree)
        {
            qualityItems--;
            if (sellInItems < 0)
            {
                qualityItems--;
            }
            else
            {
                qualityItems = 0;
            }
        }
        else if (qualityItems < 50)
        {
            qualityItems++;
            if (nameItems == nameTwo && sellInItems < 11)
            {
                qualityItems++;
            }
            else if (sellInItems < 6)
            {
                qualityItems++;
            }
        }
        else if (nameItems != nameThree)
        {
            sellInItems--;
        }
        else if (sellInItems < 0)
        {
            if (nameItems != nameOne && nameItems != nameTwo && qualityItems > 0 && nameItems != nameThree)
            {
                qualityItems--;
            }
            else if (nameItems != nameOne && nameItems != nameTwo)
            {
                qualityItems = 0;
            }
            else if (qualityItems < 50)
            {
                qualityItems++;
            }
        }
    }
}
