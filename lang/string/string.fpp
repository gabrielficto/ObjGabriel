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
};

//fun main() -> bi32 {
//    ret 0;
//}

FictoString FictoStr;