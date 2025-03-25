#!/bin/bash

# 获取项目根目录（sandbox目录）
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# 获取当前日期
CURRENT_DATE=$(date "+%Y-%m-%d")

# 获取当前版本号
CURRENT_VERSION=$(grep "project(PlanetEvolution VERSION" "$PROJECT_ROOT/CMakeLists.txt" | cut -d' ' -f3 | tr -d ')')

# 解析版本号
IFS='.' read -r -a version_parts <<< "$CURRENT_VERSION"
MAJOR="${version_parts[0]}"
MINOR="${version_parts[1]}"
PATCH="${version_parts[2]}"

# 根据参数更新版本号
case "$1" in
    "major")
        MAJOR=$((MAJOR + 1))
        MINOR=0
        PATCH=0
        ;;
    "minor")
        MINOR=$((MINOR + 1))
        PATCH=0
        ;;
    "patch")
        PATCH=$((PATCH + 1))
        ;;
    *)
        echo "Usage: $0 {major|minor|patch}"
        exit 1
        ;;
esac

NEW_VERSION="$MAJOR.$MINOR.$PATCH"

# 更新CMakeLists.txt中的版本号
sed -i "s/project(PlanetEvolution VERSION .*)/project(PlanetEvolution VERSION $NEW_VERSION)/" "$PROJECT_ROOT/CMakeLists.txt"

# 更新CHANGELOG.md
CHANGELOG_FILE="$PROJECT_ROOT/CHANGELOG.md"
if [ ! -f "$CHANGELOG_FILE" ]; then
    touch "$CHANGELOG_FILE"
fi

# 创建临时文件
TEMP_FILE=$(mktemp)
echo -e "# 更新日志\n\n## [$NEW_VERSION] - $CURRENT_DATE\n\n### 新增\n- \n\n### 变更\n- \n\n### 修复\n- \n\n### 移除\n- \n\n$(cat "$CHANGELOG_FILE")" > "$TEMP_FILE"

# 使用mv命令替换文件
mv "$TEMP_FILE" "$CHANGELOG_FILE"

echo "版本已更新到 $NEW_VERSION ($CURRENT_DATE)" 