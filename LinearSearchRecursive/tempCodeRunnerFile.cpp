if (high < low){
        return -1;
    } 
    else if (vec[low] == key){
        return low;
    } 
    else{
        return lnSrchRc(vec, (++low), high, key);
    } 