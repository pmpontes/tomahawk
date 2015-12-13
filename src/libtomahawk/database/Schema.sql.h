/*
    This file was automatically generated from ./Schema.sql on Tue Jul 30 12:51:06 CEST 2013.
*/

static const char * tomahawk_schema_sql = 
"CREATE TABLE IF NOT EXISTS oplog ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE, "
"    guid TEXT NOT NULL,"
"    command TEXT NOT NULL,"
"    singleton BOOLEAN NOT NULL,"
"    compressed BOOLEAN NOT NULL,"
"    json TEXT NOT NULL"
");"
"CREATE UNIQUE INDEX oplog_guid ON oplog(guid);"
"CREATE INDEX oplog_source ON oplog(source);"
"CREATE TABLE IF NOT EXISTS artist ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    name TEXT NOT NULL,"
"    sortname TEXT NOT NULL"
");"
"CREATE UNIQUE INDEX artist_sortname ON artist(sortname);"
"CREATE INDEX artist_name ON artist(name);"
"CREATE TABLE IF NOT EXISTS track ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    artist INTEGER NOT NULL REFERENCES artist(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    name TEXT NOT NULL,"
"    sortname TEXT NOT NULL"
");"
"CREATE UNIQUE INDEX track_artist_sortname ON track(artist,sortname);"
"CREATE INDEX track_name ON track(name);"
"CREATE TABLE IF NOT EXISTS album ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    artist INTEGER NOT NULL REFERENCES artist(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    name TEXT NOT NULL,"
"    sortname TEXT NOT NULL"
");"
"CREATE UNIQUE INDEX album_artist_sortname ON album(artist,sortname);"
"CREATE TABLE IF NOT EXISTS source ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    name TEXT NOT NULL,"
"    friendlyname TEXT,"
"    lastop TEXT NOT NULL DEFAULT \"\",       "
"    isonline BOOLEAN NOT NULL DEFAULT false"
");"
"CREATE UNIQUE INDEX source_name ON source(name);"
"CREATE TABLE IF NOT EXISTS playlist ("
"    guid TEXT PRIMARY KEY,"
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED, "
"    shared BOOLEAN DEFAULT false,"
"    title TEXT,"
"    info TEXT,"
"    creator TEXT,"
"    lastmodified INTEGER NOT NULL DEFAULT 0,"
"    currentrevision TEXT REFERENCES playlist_revision(guid) DEFERRABLE INITIALLY DEFERRED,"
"    dynplaylist BOOLEAN DEFAULT false,"
"    createdOn INTEGER NOT NULL DEFAULT 0"
");"
"CREATE TABLE IF NOT EXISTS playlist_item ("
"    guid TEXT PRIMARY KEY,"
"    playlist TEXT NOT NULL REFERENCES playlist(guid) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    trackname  TEXT NOT NULL,"
"    artistname TEXT NOT NULL,"
"    albumname  TEXT,"
"    annotation TEXT,"
"    duration INTEGER,       "
"    addedon INTEGER NOT NULL DEFAULT 0,   "
"    addedby INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED, "
"    result_hint TEXT        "
");"
"CREATE INDEX playlist_item_playlist ON playlist_item(playlist);"
"CREATE INDEX playlist_item_trackname ON playlist_item(trackname);"
"CREATE INDEX playlist_item_artistname ON playlist_item(artistname);"
"CREATE TABLE IF NOT EXISTS playlist_revision ("
"    guid TEXT PRIMARY KEY,"
"    playlist TEXT NOT NULL REFERENCES playlist(guid) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    entries TEXT, "
"    author INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    timestamp INTEGER NOT NULL DEFAULT 0,"
"    previous_revision TEXT REFERENCES playlist_revision(guid) DEFERRABLE INITIALLY DEFERRED"
");"
"CREATE TABLE IF NOT EXISTS dynamic_playlist ("
"    guid TEXT NOT NULL REFERENCES playlist(guid) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    pltype TEXT, "
"    plmode INTEGER, "
"    autoload BOOLEAN DEFAULT true "
");"
"CREATE TABLE IF NOT EXISTS dynamic_playlist_controls ("
"    id TEXT PRIMARY KEY,"
"    playlist TEXT NOT NULL REFERENCES playlist(guid) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    selectedType TEXT,"
"    match TEXT,"
"    input TEXT"
");"
"CREATE TABLE IF NOT EXISTS dynamic_playlist_revision ("
"    guid TEXT PRIMARY KEY NOT NULL REFERENCES playlist_revision(guid) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    controls TEXT, "
"    plmode INTEGER,"
"    pltype TEXT"
");"
"CREATE TABLE IF NOT EXISTS file ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    url TEXT NOT NULL,                   "
"    size INTEGER NOT NULL,               "
"    mtime INTEGER NOT NULL,              "
"    md5 TEXT,                            "
"    mimetype TEXT,                       "
"    duration INTEGER NOT NULL DEFAULT 0, "
"    bitrate INTEGER NOT NULL DEFAULT 0   "
");"
"CREATE UNIQUE INDEX file_url_src_uniq ON file(source, url);"
"CREATE INDEX file_source ON file(source);"
"CREATE INDEX file_mtime ON file(mtime);"
"CREATE TABLE IF NOT EXISTS dirs_scanned ("
"    name TEXT PRIMARY KEY,"
"    mtime INTEGER NOT NULL"
");"
"CREATE TABLE IF NOT EXISTS file_join ("
"    file INTEGER PRIMARY KEY REFERENCES file(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    artist INTEGER NOT NULL REFERENCES artist(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    track INTEGER NOT NULL REFERENCES track(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    album INTEGER REFERENCES album(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    albumpos INTEGER,"
"    composer INTEGER REFERENCES artist(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    discnumber INTEGER"
");"
"CREATE INDEX file_join_track  ON file_join(track);"
"CREATE INDEX file_join_artist ON file_join(artist);"
"CREATE INDEX file_join_album  ON file_join(album);"
"CREATE TABLE IF NOT EXISTS track_tags ("
"    id INTEGER PRIMARY KEY,   "
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    tag TEXT NOT NULL,        "
"    ns TEXT,                  "
"    weight float DEFAULT 1.0  "
");"
"CREATE INDEX track_tags_tag ON track_tags(tag);"
"CREATE TABLE IF NOT EXISTS album_tags ("
"    id INTEGER PRIMARY KEY,   "
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    tag TEXT NOT NULL,        "
"    ns TEXT,                  "
"    weight float DEFAULT 1.0  "
");"
"CREATE INDEX album_tags_tag ON album_tags(tag);"
"CREATE TABLE IF NOT EXISTS artist_tags ("
"    id INTEGER PRIMARY KEY,   "
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    tag TEXT NOT NULL,        "
"    ns TEXT,                  "
"    weight float DEFAULT 1.0  "
");"
"CREATE INDEX artist_tags_tag ON artist_tags(tag);"
"CREATE TABLE IF NOT EXISTS track_attributes ("
"    id INTEGER REFERENCES track(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,   "
"    k TEXT NOT NULL,"
"    v TEXT NOT NULL"
");"
"CREATE INDEX track_attrib_id ON track_attributes(id);"
"CREATE INDEX track_attrib_k  ON track_attributes(k);"
"CREATE TABLE IF NOT EXISTS collection_attributes ("
"    id INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED, "
"    k TEXT NOT NULL,"
"    v TEXT NOT NULL"
");"
"CREATE TABLE IF NOT EXISTS social_attributes ("
"    id INTEGER REFERENCES track(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,   "
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE, "
"    k TEXT NOT NULL,"
"    v TEXT NOT NULL,"
"    timestamp INTEGER NOT NULL DEFAULT 0"
");"
"CREATE INDEX social_attrib_id        ON social_attributes(id);"
"CREATE INDEX social_attrib_source    ON social_attributes(source);"
"CREATE INDEX social_attrib_k         ON social_attributes(k);"
"CREATE INDEX social_attrib_timestamp ON social_attributes(timestamp);"
"CREATE TABLE IF NOT EXISTS playback_log ("
"    id INTEGER PRIMARY KEY AUTOINCREMENT,"
"    source INTEGER REFERENCES source(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    track INTEGER REFERENCES track(id) ON DELETE CASCADE ON UPDATE CASCADE DEFERRABLE INITIALLY DEFERRED,"
"    playtime INTEGER NOT NULL,              "
"    secs_played INTEGER NOT NULL"
");"
"CREATE INDEX playback_log_source ON playback_log(source);"
"CREATE INDEX playback_log_track ON playback_log(track);"
"CREATE INDEX playback_log_playtime ON playback_log(playtime);"
"CREATE TABLE IF NOT EXISTS http_client_auth ("
"    token TEXT NOT NULL PRIMARY KEY,"
"    website TEXT NOT NULL,"
"    name TEXT NOT NULL,"
"    ua TEXT,"
"    mtime INTEGER,"
"    permissions TEXT NOT NULL"
");"
"CREATE TABLE IF NOT EXISTS settings ("
"    k TEXT NOT NULL PRIMARY KEY,"
"    v TEXT NOT NULL DEFAULT ''"
");"
"INSERT INTO settings(k,v) VALUES('schema_version', '31');"
    ;

const char * get_tomahawk_sql()
{
    return tomahawk_schema_sql;
}


