def get_header
    crunchbang = '#'
    <<-header
#{crunchbang}pragma once
#{crunchbang}ifndef byte
#{crunchbang}define byte unsigned char
#{crunchbang}endif

byte letter2code(char letter)
{
  switch (letter)
  {
    header
end

def close_header
    <<-header
    
    default: return '?';
  }
}
    header
end

def get_code letter
    flag = false
    code = ""

    if letter.length <= 1
        code = (letter != "\'")? "case \'#{letter}\': " : "case \'\\\'\': "
        flag = true
    end

    return code, flag
end

def format line, content
    output = "    "

    if content
        flag = false
        for bit in content.split " "
            bit, ok = get_code bit
            output += bit if ok
            flag = flag || ok
        end
        output += "return #{line}; break;" if flag
    end

    return output
end

def main inlet, outlet
    i = 0
    outlet.puts get_header
    for line in inlet
        it = format i, line
        outlet.puts it if it.rstrip.length > 0
        i += 1
    end
    outlet.puts close_header
end

b2l = "bit2letter"
inlet = File.open(b2l + ".txt", "r")
outlet = File.open(b2l + ".h", "w")
main inlet, outlet
inlet.close
outlet.close
