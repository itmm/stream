# Das `stream`-Framework

## ANFORDERUNG [AN1]: Einfaches Schreiben

1. `stream` kann zeilenweise Texte in eine Datei anfügen


Diese Anforderung beschreibt auf sehr hoher Ebene, was das `stream`-Framework
leisten soll.

Daraus resultieren direkt Akzeptanzkriterien:

## AKZEPTANZKRITERIUM [AK1] -> [AN1]: Zwei Zeilen in neue Datei schreiben

1. Die Datei `test.txt` ist vor dem Start des Tests nicht vorhanden.
2. Mit `stream` wird die Zeile `abc` in die Datei `test.txt` geschrieben.
3. Mit `stream` wird die Zeile `def` in die Datei `test.txt` geschrieben.
4. Nach dem Ende des Test-Programmes gibt es die Datei `test.txt`.
5. Die Datei `test.txt` enthält die beiden Zeilen `abc` und `def`.

## AKZEPTANZKRITERIUM [AK2] -> [AN2]: Zeile anhängen

1. Die Datei `test.txt` existiert vor dem Start des Test-Programms mit der
   einzigen Zeile `abc`.
2. Mit `stream` wird die Zeile `def` in die Datei `test.txt` geschrieben.
3. Nach dem Ende des Test-Programms enthält die Datei `test.txt` die beiden
   Zeilen `abc` und `def`.

## DESIGN [DE1] -> [AN1]: `Stream`-Klasse

In `stream.h` wird die Klasse `Stream` definiert:

```c++
#pragma once

#include <string>

class Stream {
	public:
		explicit Stream(const std::string &file_path);
		void add(const std::string &data);
};
```

## UNIT-TEST [UT1] -> [AN1],[AK1]: Zwei Zeilen in neue Datei schreiben

In `run_tests.cpp` werden alle Testläufe gebündelt:

```c++
#include "stream.h"

#include <cassert>

void run_ut1_add_lines() {
	assert(false);
}

int main() {
	run_ut1_add_lines();
}
```

```c++
// ...
#include <cassert>
#include <filesystem>
// ...
void run_ut1_add_lines() {
	std::string file_name { "test.txt" };
	std::string line_1 { "abc" };
	std::string line_2 { "def" };
	std::filesystem::remove(file_name);
	{
		Stream str { file_name };
		str.add(line_1);
		str.add(line_2);
	}
	{
		std::ifstream in { file_name };
		std::string line;
		assert(std::getline(in, line));
		assert(line == line_1);
		assert(std::getline(in, line));
		assert(line == line_2);
		assert(!std::getline(in, line));
		// ...
	}
	std::filesystem::remove(file_name);
	return;
	// ...
}
// ...
```

## CODE [CD1] -> [UT1],[AN1],[AK1]: Einfache Implementierung

`stream.h`

```c++
// ...
#include <string>
#include <fstream>
// ...
class Stream {
		std::ofstream out_;
// ...
};
```

`stream.cpp`

```c++
#include "stream.h"

#include <fstream>

Stream::Stream(const std::string &file_path):
	out_ { file_path.c_str() }
{ }

void Stream::add(const std::string &data) {
	out_ << data << "\n";
}
```

## ANFORDERUNG: Datei nur bei Bedarf erzeugen

1. Wenn mit `stream` keine Zeilen in eine Datei geschrieben werden und
   die Datei existiert noch nicht, so wird sie auch nicht erzeugt.

## ANFORDERUNG: Fehlerfall

1. Wenn die Zeile nicht geschrieben werden kann, so wird die aufrufende
   Anwendung informiert.

