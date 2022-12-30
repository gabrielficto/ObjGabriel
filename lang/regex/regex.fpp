import std
import regex

class FictoRegex {
    --publ
        fun match( entry : str rule : str ) -> boo {
            ret regex_match(entry, rule);
        }

        fun find() -> str {}
}