#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct lexicographicalComparable
{
    bool operator()(string s, string s2)
    {
        if (int(s.at(0)) == int(s2.at(0)))
        {
            int len1 = s.length();
            int len2 = s2.length();
            int len = len1 < len2 ? len1 : len2;
            int j = 0;

            for (int i = 1; i < len; i++)
            {
                int j = i;
                if (int(s.at(i)) != int(s2.at(i)))
                {
                    return int(s.at(i)) < int(s2.at(i));
                }
            }

            return int(s.at(j)) < int(s2.at(j));
        }
        else
        {
            return int(s.at(0)) < int(s2.at(0));
        }
    }
};

vector<vector<string> > groupingDishes(vector<vector<string> > dishes)
{
    unordered_map<string, vector<string> > map;
    lexicographicalComparable comparable;
    vector<string> keys;

    for (vector<string> dish : dishes)
    {
        string dishName = dish.at(0);

        for (int i = 1; i < dish.size(); i++)
        {
            string ingredient = dish.at(i);
            if (map.find(ingredient) != map.end())
            {
                vector<string> val = map[ingredient];
                val.push_back(dishName);

                map[ingredient] = val;
            }
            else
            {
                keys.push_back(ingredient);

                vector<string> val;
                val.push_back(dishName);

                map.insert(make_pair(ingredient, val));
            }
        }
    }

    std::sort(keys.begin(), keys.end(), comparable);

    vector<vector<string> > res;
    for (auto key : keys)
    {
        vector<string> res2;
        vector<string> dishes = map[key];
        std::sort(dishes.begin(), dishes.end(), comparable);

        // - push new element
        // if at least has 2 dishes
        if (dishes.size() > 1)
        {
            res2.push_back(key);
            for (auto dish : dishes)
            {
                res2.push_back(dish);
            }

            // push all elements
            res.push_back(res2);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    /**
     * @brief
     * 
     * The LinkedIn interview test.
     * 
     * You are given a list dishes, where each element consists of a list of strings beginning with the name of the dish,
     * followed by all the ingredients used in preparing it. You want to group the dishes by ingredients, so that for each ingredient
     * you'll be able to find all the dishes that contain it (if there are at least 2 such dishes).
     * 
     * For dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
            ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
            ["Quesadilla", "Chicken", "Cheese", "Sauce"],
            ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]
     *
     * The output should be: 
     * groupingDishes(dishes) = [   ["Cheese", "Quesadilla", "Sandwich"],
     *                              ["Salad", "Salad", "Sandwich"],
     *                              ["Sauce", "Pizza", "Quesadilla", "Salad"],
     *                              ["Tomato", "Pizza", "Salad", "Sandwich"]
     *                          ]
     */
    return 0;
}
