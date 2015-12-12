module Bit2Letter
    def Bit2Letter::main arg
        inlet = File.open arg, 'r'
        outlet = File.open 'bit2letter.h', 'w'
        draw outlet, setup(inlet)
        inlet.close
        outlet.close
    end

    def Bit2Letter::get_header
        crunchbang = '#'
        <<-header
#{crunchbang}pragma once
#{crunchbang}ifndef byte
#{crunchbang}define byte unsigned char
#{crunchbang}endif

        header
    end

    def Bit2Letter::open_letter2code
        <<-header
byte letter2code(char letter)
{
  switch (letter)
  {
    case ' ': return 0; break;
        header
    end

    def Bit2Letter::close_letter2code
        <<-header

    default: return '?';
  }
}

        header
    end

    def Bit2Letter::open_precedence
        <<-header
byte get_precedence(char letter)
{
  switch (letter)
  {
        header
    end

    def Bit2Letter::close_precedence
        <<-header
    default: return 0;
  }
}
        header
    end

    def Bit2Letter::setup inlet
        out = {}

        for line in inlet
            out = extract_info line, out
        end

        return out
    end

    def Bit2Letter::draw outlet, info
        outlet.puts get_header

        # letter2code function
        outlet.puts open_letter2code
        for key, value in info
            outlet.puts "    case '#{key}': return #{value['code']}; break;"
        end
        outlet.puts close_letter2code

        # precedence function
        outlet.puts open_precedence
        for key, value in info
            precedence = value['precedence']
            if precedence > 0
                outlet.puts "    case '#{key}': return #{precedence}; break;"
            end
        end
        outlet.puts close_precedence
    end

    def Bit2Letter::extract_info line, info
        bits = line.split /\s+/

        for bit in bits
            print bit + ' '
        end
        puts

        info[bits[0]] = { 'precedence' => get_precedence(bits),
                          'code' => get_code(bits) } if bits[0].length > 0
        info
    end

    def Bit2Letter::get_precedence bits
        precedence = 0

        if bits[9] != 'x'
            precedence = 0
            for i in 0...6
                precedence += 2**i if bits[9+i].to_i != 0
            end
        end

        return precedence
    end

    def Bit2Letter::get_code bits
        code = 0

        for i in 0...6
            code += 2**i if bits[15+i].to_i != 0
        end

        return code
    end
end

if __FILE__ == $0
    ARGV.each do |arg|
        Bit2Letter::main arg
    end
end
