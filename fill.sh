for d in {07..31}
do
  for i in {1..4}
  do
    echo "$d-$i" >> graph.txt
    git add .
    GIT_AUTHOR_DATE="2026-03-$d 10:00:00" GIT_COMMITTER_DATE="2026-03-$d 10:00:00" git commit -m "March $d commit $i"
  done
done

for d in {01..02}
do
  for i in {1..4}
  do
    echo "$d-$i" >> graph.txt
    git add .
    GIT_AUTHOR_DATE="2026-04-$d 10:00:00" GIT_COMMITTER_DATE="2026-04-$d 10:00:00" git commit -m "April $d commit $i"
  done
done
^X
X



