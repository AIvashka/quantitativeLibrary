//
// Created by Alexey Ivashka on 9.01.22.
//

#ifndef OPTIONS_OPTIONBASE_HPP
#define OPTIONS_OPTIONBASE_HPP


enum class OptionType {
    Call,
    Put
};

class OptionBase {

private:
    double StrikePrice;
    double Volatility;
    double InterestRate;
    double TimeToExpiration;
    OptionType Type;


public:
    OptionBase() : StrikePrice(0), Volatility(0), InterestRate(0), TimeToExpiration(0) {};
    explicit OptionBase(double StrikePrice, double Volatility, double InterestRate, double TimeToExpiration, OptionType OptionType) :
                                                        StrikePrice(StrikePrice),
                                                        Volatility(Volatility),
                                                        InterestRate(InterestRate),
                                                        TimeToExpiration(TimeToExpiration),
                                                        Type(OptionType) {}

    double GetOptionPrice() const;
    friend std::ostream& operator<<(std::ostream& out, const OptionBase& option);
};

std::ostream &operator<<(std::ostream& out, const OptionType& Type) {
    std::string type = Type == OptionType::Call ? "Call" : "Put";
    out << type << std::endl;
}

std::ostream &operator<<(std::ostream& out, const OptionBase& option) {
    out << "————————————————————————" << std::endl;
    out << "OptionType : " << option.Type << std::endl;
    out << "StrikePrice : " << option.StrikePrice << std::endl;
    out << "Volatility : " << option.Volatility << std::endl;
    out << "InterestRate : " << option.InterestRate << std::endl;
    out << "TimeToExpiration : " << option.TimeToExpiration << std::endl;
    out << "————————————————————————" << std::endl;
    return out;
}

#endif //OPTIONS_OPTIONBASE_HPP
