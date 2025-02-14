class ProductOfNumbers {
public:
    vector<long long> prods;
    int size = 0;

    ProductOfNumbers() {
        prods.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            prods = {1};
            size = 0;
        } else {
            long long prod = prods[size] * num;
            prods.push_back(prod);
            size++; 
        }
    }
    
    int getProduct(int k) {
        if(k > size)
            return 0;

        return (int) prods[size] / prods[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */