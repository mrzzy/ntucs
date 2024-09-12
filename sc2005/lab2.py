#
# NTU CS
# SC2005 Lab 2
# Convert Lab 2 output to Submission CSV
# Usage: output.py output.txt
#   output.txt: Debug output from nachos -d

import sys
import re
import csv


if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        # discard first section
        sections = f.read().split("==")[1:]

    with open("output.csv", "w") as f:
        out = csv.DictWriter(
            f,
            [
                "Tick",
                "ready list",
                "current thread",
                "Timer Interrupt triggered",
                "Thread completion",
                "Context switch",
            ],
        )
        out.writeheader()

        # thread state
        ready, current = [], "main"
        current = "main"

        # parse tick sections into csv row
        for i in range(len(sections) // 2):
            tick = int(sections[i * 2].split()[-1])
            content = sections[i * 2 + 1]

            # timer interrupt
            timer = "n/a"
            if match := re.search(
                r"Scheduling interrupt handler the timer at time = (\d+)", content):
                timer = f"timer interrupt scheduled at {match[1]}"

            # thread finishing
            finished = "n/a"
            if match := re.search(
                r"Finishing thread (\w+) #0", content):
                finished = f"{match[1]} Completed"

            # content switch between threads
            switch_to = None
            if match := re.search(
                r"Switching from thread \w+ #0 to thread (\w+) #0", content
            ):
                switch_to = match[1]
            out.writerow(
                {
                    "Tick": tick,
                    "ready list": "empty" if len(ready) == 0 else " ".join(ready),
                    "current thread": current,
                    "Timer Interrupt triggered": timer,
                    "Thread completion": finished,
                    "Context switch": "n/a" if switch_to is None else switch_to,
                }
            )
            # threads placed on ready list
            if match := re.search(r"Putting thread (\w+) #0 on ready list.", content):
                ready.append(match[1])
            # apply context switch on next tick
            if switch_to is not None:
                current = switch_to
                ready.remove(current)
