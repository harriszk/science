package calculator;

import java.util.HashMap;
import java.util.Map;

public enum PrefixMultipliers {
    YOTTA(24, "Y"),
    ZETTA(21, "Z"),
    EXA(18, "E"),
    PETA(15, "P"),
    TERA(12, "T"),
    GIGA(9, "G"),
    MEGA(6, "M"),
    KILO(3, "k"),
    DECI(-1, "d"),
    CENTI(-2, "c"),
    MILLI(-3, "m"),
    MICRO(-6, "μ"),
    NANO(-9, "n"),
    PICO(-12, "p"),
    FEMTO(-15, "f"),
    ATTO(-18, "a"),
    ZEPTO(-21, "z"),
    YOCTO(-24, "y");

    final int multiplier;
    final String symbol;

    PrefixMultipliers(int multiplier, String symbol)
    {
        this.multiplier = multiplier;
        this.symbol = symbol;
    }

    // Get multipler by symbol
    // https://stackoverflow.com/questions/1080904/how-can-i-lookup-a-java-enum-from-its-string-value
}