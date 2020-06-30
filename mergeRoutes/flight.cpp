#include <iostream>
#include <vector>
#include <string>


// This function will merge all flight routes together with a starting point from 
// JFK airport 
// I wrote this for fun, based on LeetCode problem 322
std::vector<std::string> mergeRoutes(std::vector<std::vector<std::string>>& routes)
{
    //Base cases-------------------------------------------------------------------
    if (routes.size() == 0)
    {
        return std::vector<std::string> {{"There are no routes to merge"}};
    }
    if (routes.size() == 1)
    {
        return std::vector<std::string> {routes[0]};
    }
    //-----------------------------------------------------------------------------

    //Check if JFK airport is on the list of routes, if there is then put it as a starting point
    std::vector<std::string> mergedRoute;
    for (int i = 0; i < routes.size(); i++)
    {
        if (routes[i][0] == "JFK")
        {
            mergedRoute.emplace_back(routes[i][0]);
            mergedRoute.emplace_back(routes[i][1]);
            break;
        }
    }
    if (mergedRoute.size() == 0)
    {
        return std::vector<std::string> {{"Can't find the starting point"}};
    }
    //-----------------------------------------------------------------------------

    //Routing engine---------------------------------------------------------------
    for (int i = 1; i < routes.size(); i++)
    {
        for (int j = 0; j < routes.size(); j++)
        {
            if (routes[j][0] == mergedRoute[i])
            {
                mergedRoute.emplace_back(routes[j][1]);
            }
        }
    }
    //------------------------------------------------------------------------------

    //return results
    return mergedRoute;
};

//Driver code------------------------------------------------------------------------
int main() 
{
    std::vector<std::vector<std::string>> tickets 
    { 
        {"MUC", "LHR"}, 
        {"JFK", "MUC"}, 
        {"SFO", "SJC"}, 
        {"LHR", "SFO"}
    };
    std::vector<std::string> results = mergeRoutes(tickets);
    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
    return 0;
}