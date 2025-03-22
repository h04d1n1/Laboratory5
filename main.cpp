#include "Deposit.cpp"
#include <iostream>
#include <set>
#include <unordered_set>

int main()
{
    std::set<Deposit> st;
    std::unordered_set<Deposit, DepositHasher> unst;
    
    std::ifstream in("input.txt");
    for (int i = 0; i < 3; i++)
    {
        std::string lbl, cur;
        int v;
        float r;
        in >> lbl >> v >> cur >> r;

        st.insert(Deposit(lbl, v, cur, r));
        unst.insert(Deposit(lbl, v, cur, r));
    }
    in.close();

    std::ofstream out("output.txt");
    for (auto &pos : unst)
    {
        out << pos.getLabel() << " " << pos.getValue() << " "
            << pos.getCurrencyType() << " " << pos.getRate() << "\n";
    }
    out << "\n";
    for (auto &pos : st)
    {
        out << pos.getLabel() << " " << pos.getValue() << " "
            << pos.getCurrencyType() << " " << pos.getRate() << "\n";
    }
    return 0;
}
