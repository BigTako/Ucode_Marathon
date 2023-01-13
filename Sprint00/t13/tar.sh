while getopts 'ce:' flag; do
  case "$flag" in
    c)
      tar -cf "$2" ${@:3}
      ;;
    e)
      tar --extract -f "$2"
      ;;
  esac
done


