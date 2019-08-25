class FileSystem {
public:
    map<string, int>hax;
    FileSystem() {
        hax.clear();
    }
    
    bool create(string path, int value) {
        for(int i=path.size();i>=0;i--) {
            if(path[i] =='/') {
                if(i==0) {
                    hax[path] = value;
                    return true;
                } else {
                    string k = path.substr(0, i);
                    if(!hax.count(k)) {
                        return false;
                    } else {
                        hax[path] = value;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    int get(string path) {
        if(hax.count(path))
        return hax[path];
        else return -1;
    }
};
