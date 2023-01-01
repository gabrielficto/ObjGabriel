import std

class FictoString {
    --publ
        fun getLength( _str : str ) -> bi32 {
            ret _str.length();
        }

        fun isEmpty( _str : str ) -> boo {
            return _str.empty();
        }

        fun equals( _str1 : str _str2 : str ) -> boo {
            return (_str1 == _str2);
        }

        fun find( text : str query : str ) -> bi32 {
            ret text.find(query);
        }

        fun replace( orig : str repl : str replWith : str ) -> str {
            ret orig.replace(orig.find(repl), repl.length(), replWith);
        }
};

FictoString FictoStr;

fun main() -> bi32 {
    ret 0;
}