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

    def Bit2Letter::setup inlet
        out = {}
        no_line = 0

        for line in inlet
            bits = line.split /\s+/
            if bits[0].length > 0
                out[no_line] = bits[0]
            end

            no_line += 1
        end

        return out
    end

    def Bit2Letter::draw outlet, info
        outlet.puts get_header
        outlet.puts open_letter2code
        for key, value in info
            puts "#{key}: '#{value}'"
        end
        outlet.puts close_letter2code
    end
end

if __FILE__ == $0
    ARGV.each do |arg|
        Bit2Letter::main arg
    end
end
