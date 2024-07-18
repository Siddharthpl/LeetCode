class Solution {
public:

    

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int PickingtP = 0;
        int TraveltP = 0;
        int lastHouseP = 0;

        int PickingtG = 0;
        int TraveltG = 0;
        int lastHouseG = 0;

        int PickingtM = 0;
        int TraveltM = 0;
        int lastHouseM = 0;

        for(int i=0;i<garbage.size();i++){

            string CurrString = garbage[i];

            for(int j=0;j<CurrString.length();j++){
                if(CurrString[j] == 'P'){
                    PickingtP++;
                    lastHouseP = i;
                }
                if(CurrString[j] == 'G'){
                    PickingtG++;
                    lastHouseG = i;
                }
                if(CurrString[j] == 'M'){
                    PickingtM++;
                    lastHouseM = i;
                }
            }
        }

        
        for(int i=0;i<lastHouseP;i++){
            TraveltP = TraveltP + travel[i];
        }
        for(int i=0;i<lastHouseG;i++){
            TraveltG = TraveltG + travel[i];
        }
        for(int i=0;i<lastHouseM;i++){
            TraveltM = TraveltM + travel[i];
        }

        int TotalPickingTime = PickingtP + PickingtG + PickingtM;
        int TotalTravelTime = TraveltP + TraveltG + TraveltM;

        return (TotalPickingTime + TotalTravelTime);

        
    }
};